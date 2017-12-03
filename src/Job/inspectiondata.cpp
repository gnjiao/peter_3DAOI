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
//    SqliteDB sqlite(path);
//    try
//    {
//        auto isOpened = sqlite.isOpened();
//        if(isOpened)
//        {
//            //>>>----------------------------------------------------------------------------------------------------------
//            //1.读取版本号
//            std::string Version{"V1"};
//            std::string selectedString = "select Version from Job";
//            sqlite.prepare(selectedString);
//            Version = sqlite.executeScalar<std::string>(selectedString);

//            bool isConvertToV1 = false;
//            if( "V2" != Version )
//            {
//                if( "V1" == Version )
//                {
//                    isConvertToV1 = true;
//                    std::cout << "读取程序的版本为V1，进行自动的版本转换, 数据库更新为V2" << std::endl;
//                    //convertFromV1(sqlite);
//                    return;
//                }
//            }
//            else
//            {
//                auto isOpened = sqlite.isOpened();
//                if(isOpened)
//                {
//                    //>>>----------------------------------------------------------------------------------------------------------
//                    //1.读取版本号
//                    std::string selectedString = "select Version from Job";
//                    sqlite.prepare(selectedString);
//                    Version = sqlite.executeScalar<std::string>(selectedString);

//                    if(Version!="V1")
//                    {
//                        throw std::string("读取程序的版本不对，读取中止");
//                    }

//                    //>>>----------------------------------------------------------------------------------------------------------
//                    //2.读取Target表
//                    selectedString = "select * from Pad";
//                    bool ret = sqlite.prepare(selectedString);
//                    ret = sqlite.begin();

//                    while(true)
//                    {
//                        sqlite.step();
//                        if (sqlite.latestErrorCode() == SQLITE_DONE)
//                        {
//                            break;
//                        }

//                        //创建具体的对象
//                        Pad target;
//                        auto x = sqlite.columnValue(0);
//                        auto y = sqlite.columnValue(1);
//                        target.X =  boost::get<int>(x);
//                        target.Y =  boost::get<int>(y);
//                        PadVec.push_back(target);
//                    }

//                    sqlite.reset();
//                    sqlite.close();
//                }
//            }

//            sqlite.reset();
//            sqlite.close();
//        }
//    }
//    catch(std::string& ex)
//    {
//        std::cout<<ex.data()<<std::endl;
//        if(sqlite.isOpened())
//        {
//            sqlite.reset();
//            sqlite.close(); //发生异常了需要特别注意需要关闭数据库
//        }
//    }
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

    sqlInsert = "INSERT INTO MeasureObjs(name, xPos, yPos, width,height) VALUES(?,?,?,?,?);";
    Job::MeasuredObj* pTemp = this->board().measuredList().pHead();
    const int objsCnt = this->board().measuredList().size();
    for (int i = 0; i < objsCnt; ++i)
    {
        v1Sqlite.execute( sqlInsert,
                          pTemp->name(),
                          pTemp->body().xPos(),
                          pTemp->body().yPos(),
                          pTemp->body().width(),
                          pTemp->body().height() );
        pTemp = pTemp->pNext();
    }
    pTemp = nullptr;
    v1Sqlite.close();
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
