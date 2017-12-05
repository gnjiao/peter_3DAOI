#include "inspectiondata.hpp"

using namespace Job;
using namespace SSDK::DB;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor function
InspectionData::InspectionData()
{

}

InspectionData::~InspectionData()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//write & read & print function
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

void InspectionData::print()
{
    std::cout<<std::setw(20)<<std::left<<"board version:"<<m_version<<std::endl
            <<std::setw(20)<<std::left<<"last editing time:"<<m_lastEditingTime<<std::endl;
    //调用打印检测程式文件的Board信息
    m_board.print();
}

void InspectionData::readFromDB(const std::string &path)
{
    SqliteDB sqlite(path);
    try
    {
        if(sqlite.isOpened())
        {
            //读取版本号
            std::string selectedString = "select Version from Job";
            sqlite.prepare(selectedString);
            std::string Version = sqlite.executeScalar<std::string>(selectedString);

            if( "V2" == Version )
            {
                readCurrentVersionDB(sqlite);
            }
             else if ( "V1" == Version )
            {
                std::cout << "Convert V1 to V2!" << std::endl;
                convertFromV1(sqlite);
//                return;
            }
            else
            {
                THROW_EXCEPTION("Read sqlite error!");
            }
        }
    }
    catch(SDK::CustomException& ex)
    {
        if(sqlite.isOpened())
        {
            sqlite.reset();
            sqlite.close(); //发生异常了需要特别注意需要关闭数据库
        }
        THROW_EXCEPTION(ex.what());
    }
}

void InspectionData::writeToDB(const std::string& path)
{
    //>>>----------------------------------------------------------------------------------------------------------
    //1.写入版本信息和最后编辑时间
    SqliteDB v2Sqlite;
    v2Sqlite.open(path);

    std::string sqlcreate = "CREATE TABLE if not exists Job(Version TEXT,LastEditingTime TEXT);";
    v2Sqlite.execute( sqlcreate );
    std::string sqlInsert = "INSERT INTO Job(Version,LastEditingTime) VALUES(?,?);";
    v2Sqlite.execute( sqlInsert, this->version(), this->editingTime() );

    //>>>----------------------------------------------------------------------------------------------------------
    //2.写board表头
    sqlcreate = "CREATE TABLE if not exists Board(name TEXT,originalX REAL,originalY REAL,sizeX REAL,sizeY REAL);";
    v2Sqlite.execute( sqlcreate );

    sqlInsert = "INSERT INTO Board(name, originalX, originalY, sizeX, sizeY) VALUES(?,?,?,?,?);";
    v2Sqlite.execute( sqlInsert,
                      this->board().name(),
                      this->board().originalX(),
                      this->board().originalY(),
                      this->board().sizeX(),
                      this->board().sizeY() );

    //>>>----------------------------------------------------------------------------------------------------------
    //3.写入数据库数据
    sqlcreate = "CREATE TABLE if not exists MeasureObjs(name TEXT, xPos REAL, yPos REAL, angle REAL, width REAL, height REAL);";
    v2Sqlite.execute( sqlcreate );

    //执行插入语句
    sqlInsert = "INSERT INTO MeasureObjs(name, xPos, angle, yPos, width,height) VALUES(?,?,?,?,?,?);";
    v2Sqlite.prepare(sqlInsert);
    v2Sqlite.begin();
    Job::MeasuredObj* pTemp = this->board().measuredList().pHead();
    while( nullptr != pTemp )
    {
        std::string str = pTemp->name();
        v2Sqlite.executeWithParms( str.data(),
                                   pTemp->body().xPos(),
                                   pTemp->body().yPos(),
                                   pTemp->body().angle(),
                                   pTemp->body().width(),
                                   pTemp->body().height() );
        pTemp = pTemp->pNext(); //将临时指针指向链表中下一个元素
    }
    v2Sqlite.commit();          //将数据列表中的数据一次性写入数据库
    v2Sqlite.close();           //关闭数据库
}

void InspectionData::readCurrentVersionDB(SqliteDB& sqlite)
{
    try
    {
        if(sqlite.isOpened())
        {
            //读取Job信息
            std::string selectedString = "select Version from Job";
            sqlite.prepare(selectedString);
            std::string version = sqlite.executeScalar<std::string>(selectedString);
            this->setVersion(version);

            selectedString = "select LastEditingTime from Job";
            sqlite.prepare(selectedString);
            std::string editTime = sqlite.executeScalar<std::string>(selectedString);
            this->setEditingTime(editTime);

            //读取Board信息
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
                auto angle = sqlite.columnValue(3);
                auto width = sqlite.columnValue(4);
                auto height = sqlite.columnValue(5);

                pMeasureObj->setName(boost::get<std::string>(name));
                pMeasureObj->body().setPosX(boost::get<double>(posX));
                pMeasureObj->body().setPosY(boost::get<double>(posY));
                pMeasureObj->body().setAngle(boost::get<double>(angle));
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
            THROW_EXCEPTION("Open file error!");
        }
    }
    catch( SDK::CustomException& ex)
    {
        if(sqlite.isOpened())
        {
            sqlite.reset();
            sqlite.close(); //发生异常了需要特别注意需要关闭数据库
        }
        THROW_EXCEPTION(ex.what());
    }
}

void InspectionData::convertFromV1(SqliteDB& sqlite)
{
    try
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1.读取Job表

        //删除原来的Job表
        std::string deleteSql = "DROP TABLE Job";
        sqlite.execute(deleteSql);

        //创建新的Job表
        auto time = std::time(nullptr);
        this->setVersion("V2");
        this->setEditingTime(asctime(localtime (&time)));

        //插入版本,最近一次的编辑时间信息
        std::string sqlcreate = "CREATE TABLE if not exists Job(Version TEXT,LastEditingTime TEXT);";
        sqlite.execute( sqlcreate );
        std::string sqlInsert = "INSERT INTO Job(Version,LastEditingTime) VALUES(?,?);";
        sqlite.execute( sqlInsert, this->version(), this->editingTime() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.读取Board表
        //读取Board信息
        std::string selectedString = "select name from Board";
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

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.读取MeasureObjs信息
        //读取V1版本MeasureObjs信息
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
        //删除V1版本的MeasureObjs表
        deleteSql = "DROP TABLE MeasureObjs";
        sqlite.execute(deleteSql);
        //创建新的MeasureObjs表
        sqlcreate = "CREATE TABLE if not exists MeasureObjs(name TEXT, xPos REAL, yPos REAL, angle REAL, width REAL, height REAL);";
        sqlite.execute( sqlcreate );
        //执行插入语句
        sqlInsert = "INSERT INTO MeasureObjs(name, xPos, angle, yPos, width,height) VALUES(?,?,?,?,?,?);";
        sqlite.prepare(sqlInsert);
        sqlite.begin();
        Job::MeasuredObj* pTemp = this->board().measuredList().pHead();
        while( nullptr != pTemp )
        {
            std::string str = pTemp->name();
            sqlite.executeWithParms( str.data(),
                                     pTemp->body().xPos(),
                                     pTemp->body().yPos(),
                                     pTemp->body().angle(),
                                     pTemp->body().width(),
                                     pTemp->body().height() );
            pTemp = pTemp->pNext(); //将临时指针指向链表中下一个元素
        }
        sqlite.commit();          //将数据列表中的数据一次性写入数据库
        sqlite.close();
    }
    catch( SDK::CustomException& ex)
    {
        if(sqlite.isOpened())
        {
            sqlite.reset();
            sqlite.close(); //发生异常了需要特别注意需要关闭数据库
        }
        THROW_EXCEPTION(ex.what());
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
