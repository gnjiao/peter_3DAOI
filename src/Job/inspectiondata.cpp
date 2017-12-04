#include "inspectiondata.hpp"

using namespace Job;
using namespace SSDK::DB;

InspectionData::InspectionData()
{

}

InspectionData::~InspectionData()
{

}

void InspectionData::print()
{
    std::cout<<std::setw(20)<<std::left<<"board version:"<<m_version<<std::endl
            <<std::setw(20)<<std::left<<"last editing time:"<<m_lastEditingTime<<std::endl;
    m_board.print();
}

void InspectionData::writeToXml(const QString& path)
{
    QDomDocument doc;
    // 根元素 <Blogs>
    QDomElement job = doc.createElement("Job");
    job.setAttribute("LastEditTime",this->editingTime().c_str());  // 属性
    job.   setAttribute("Version",this->version().c_str());
    doc.appendChild(job);

    this->board().writeToXml(doc,job);

    // 保存 XML 文件
    QString strFile(path);
    QFile file(strFile);
    // 只写模式打开文件
    if (file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        doc.save(out, QDomNode::EncodingFromDocument);
        file.close();
    }
}

void InspectionData::readFromDB(const std::string &path)
{
    SqliteDB sqlite(path);
    try
    {
        auto isOpened = sqlite.isOpened();
        if(isOpened)
        {
            //>>>----------------------------------------------------------------------------------------------------------
            //1.判断是否为V1版本
            std::string selectedString = "select Version from Job";
            sqlite.prepare(selectedString);
            std::string version = sqlite.executeScalar<std::string>(selectedString);

            if( "V1" == version )
            {
                //读取版本号信息
                this->setVersion(version);

                selectedString = "select LastEditingTime from Job";
                sqlite.prepare(selectedString);
                std::string editTime = sqlite.executeScalar<std::string>(selectedString);
                this->setEditingTime(editTime);

                //读取板子信息
                selectedString = "select name from Board";
                sqlite.prepare(selectedString);
                std::string boadName = sqlite.executeScalar<std::string>(selectedString);
                this->board().setName(boadName);

                selectedString = "select originalX from Board";
                sqlite.prepare(selectedString);
                double originX = sqlite.executeScalar<double>(selectedString);
                this->board().setOriginalX(originX);

                selectedString = "select originalY from Board";
                sqlite.prepare(selectedString);
                double originY = sqlite.executeScalar<double>(selectedString);
                this->board().setOriginalY(originY);

                selectedString = "select sizeX from Board";
                sqlite.prepare(selectedString);
                double sizeX = sqlite.executeScalar<double>(selectedString);
                this->board().setSizeX(sizeX);

                selectedString = "select sizeY from Board";
                sqlite.prepare(selectedString);
                double sizeY = sqlite.executeScalar<double>(selectedString);
                this->board().setSizeY(sizeY);

                //读取Rectangle信息
                selectedString = "select * from MeasureObjs";
                bool ret = sqlite.prepare(selectedString);
                ret = sqlite.begin();
                Job::MeasuredObj* pMeasureObj = nullptr;
                while(true)
                {
                    sqlite.step();
                    if (sqlite.latestErrorCode() == SQLITE_DONE)
                    {
                        break;
                    }
                    //创建具体的对象
                    pMeasureObj = new Job::MeasuredObj();
                    auto name = sqlite.columnValue(0);
                    auto posX = sqlite.columnValue(1);
                    auto posY = sqlite.columnValue(2);
                    auto width = sqlite.columnValue(3);
                    auto height = sqlite.columnValue(4);

                    pMeasureObj->setName(boost::get<std::string>(name));
                    pMeasureObj->body().setPosX(boost::get<double>(posX));
                    pMeasureObj->body().setPosY(boost::get<double>(posY));
                    pMeasureObj->body().setWidth(boost::get<double>(width));
                    pMeasureObj->body().setHeight(boost::get<double>(height));

                    this->board().measuredList().pushBack(*pMeasureObj);
                }
                pMeasureObj = nullptr;
                sqlite.reset();
                sqlite.close();
            }
            else
            {
                throw std::string("读取程序的版本不对，读取中止!");
            }
        }
        else
        {
            throw std::string("打开文件失败,读取终止!");
        }
    }
    catch(std::string& ex)
    {
        std::cout<<ex.data()<<std::endl;
        if(sqlite.isOpened())
        {
            sqlite.reset();
            sqlite.close(); //发生异常了需要特别注意需要关闭数据库
        }
    }
}

void InspectionData::writeToDB(const std::string& path)
{
    //>>>----------------------------------------------------------------------------------------------------------
    //1.写入版本信息和最后编辑时间
    auto v1Path = path;
    SqliteDB v1Sqlite;
    v1Sqlite.open(v1Path);

    std::string sqlcreate = "CREATE TABLE if not exists Job(Version TEXT,LastEditingTime TEXT);";
    v1Sqlite.execute( sqlcreate );
    std::string sqlInsert = "INSERT INTO Job(Version,LastEditingTime) VALUES(?,?);";
    v1Sqlite.execute( sqlInsert, this->version(), this->editingTime() );

    //>>>----------------------------------------------------------------------------------------------------------
    //2.写board表头
    sqlcreate = "CREATE TABLE if not exists Board(name TEXT,originalX REAL,originalY REAL,sizeX REAL,sizeY REAL);";
    v1Sqlite.execute( sqlcreate );

    sqlInsert = "INSERT INTO Board(name, originalX, originalY, sizeX, sizeY) VALUES(?,?,?,?,?);";
    v1Sqlite.execute( sqlInsert,
                      this->board().name(),
                      this->board().originalX(),
                      this->board().originalY(),
                      this->board().sizeX(),
                      this->board().sizeY() );

    //>>>----------------------------------------------------------------------------------------------------------
    //3.写入数据库数据
    sqlcreate = "CREATE TABLE if not exists MeasureObjs(name TEXT, xPos REAL, yPos REAL, width REAL, height REAL);";
    v1Sqlite.execute( sqlcreate );

    //执行插入语句
    sqlInsert = "INSERT INTO MeasureObjs(name, xPos, yPos, width,height) VALUES(?,?,?,?,?);";
    v1Sqlite.prepare(sqlInsert);
    v1Sqlite.begin();
    Job::MeasuredObj* pTemp = this->board().measuredList().pHead();
    while( nullptr != pTemp )
    {
        std::string str = pTemp->name();
        v1Sqlite.executeWithParms( str.data(),
                                   pTemp->body().xPos(),
                                   pTemp->body().yPos(),
                                   pTemp->body().width(),
                                   pTemp->body().height() );
        pTemp = pTemp->pNext(); //将临时指针指向链表中下一个元素
    }
    v1Sqlite.commit();          //将数据列表中的数据一次性写入数据库
    v1Sqlite.close();           //关闭数据库
}

/*
void convertFromV1( SqliteDB& sqlite )
{
    //>>>----------------------------------------------------------------------------------------------------------
    //1. 读取Pad
    auto selectedString = "select * from Pad";
    bool ret = sqlite.prepare(selectedString);
    ret = sqlite.begin();
    while(true)
    {
        sqlite.step();
        if (sqlite.latestErrorCode() == SQLITE_DONE)
        {
            break;
        }

        //创建具体的对象
        Pad pad;
        auto x = sqlite.columnValue(0);
        auto y = sqlite.columnValue(1);
        pad.CenterX =  (double)boost::get<int>(x);//这里原来的数据类型是int的，新改了之后是double的，需要转换下
        pad.CenterY =  (double)boost::get<int>(y);
        pad.Angle = 0; // 默认的角度是0度
        PadVec.push_back(pad);
    }

    //>>>----------------------------------------------------------------------------------------------------------
    //2. 读取Library
    //V1是没有Library数据结构的， 所以默认创建2个
    int padCnt = PadVec.size();
    for (int i = 0; i < padCnt; ++i)
    {
           Library lib{0,0};
           LibraryVec.push_back(lib);
    }

    sqlite.reset();
    sqlite.close();

    //>>>----------------------------------------------------------------------------------------------------------
    //3.重新写Job表头
    auto v2Path = sqliteDataPath+"v2";
    SqliteDB v2Sqlite;
    v2Sqlite.open(v2Path);

    string sqlcreate = "CREATE TABLE if not exists Job(Version TEXT);";
    v2Sqlite.execute(sqlcreate);
    string sqlInsert = "INSERT INTO Job(Version) VALUES('V2');";
    v2Sqlite.execute(sqlInsert);

    //>>>----------------------------------------------------------------------------------------------------------
    //4.重新写数据库(Pad表)

   //删除原来的Pad表
   string deleteSql = "DROP TABLE Pad";
   v2Sqlite.execute(deleteSql);

    //创建新的Pad表
   sqlcreate = "CREATE TABLE if not exists Pad(CenterX REAL, CenterY REAL, Angle REAL);";
   v2Sqlite.execute(sqlcreate);

   //插入现有的记录
   sqlInsert = "INSERT INTO Pad(CenterX,CenterY,Angle) VALUES(?,?,?);";
   for (int i = 0; i < padCnt; ++i)
   {
       v2Sqlite.execute(sqlInsert, PadVec[i].CenterX, PadVec[i].CenterY, PadVec[i].Angle);
   }

   //>>>----------------------------------------------------------------------------------------------------------
   //5.重新写数据库(Library表)
   //创建新的Pad表
   sqlcreate = "CREATE TABLE if not exists Library(Width REAL, Height REAL);";
   v2Sqlite.execute(sqlcreate);

   //插入现有的记录
   sqlInsert = "INSERT INTO Library(Width,Height) VALUES(?,?);";
   for (int i = 0; i < padCnt; ++i)
   {
       v2Sqlite.execute(sqlInsert, LibraryVec[i].Width, LibraryVec[i].Height);
   }

   v2Sqlite.close();
}

*/
