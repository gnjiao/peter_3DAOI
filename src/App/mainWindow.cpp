#include "mainWindow.hpp"

using namespace App;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor
MainWindow::MainWindow()
{

}

MainWindow::~MainWindow()
{
    Job::MeasuredObj * pTmpObj = nullptr;
    while ( nullptr != this->m_inspectionData.board().measuredList().pHead() )
    {
        pTmpObj = this->m_inspectionData.board().measuredList().pHead()->pNext();
        delete this->m_inspectionData.board().measuredList().pHead();
        this->m_inspectionData.board().measuredList().setHead(pTmpObj);
    }
    pTmpObj = nullptr;
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//load configure & scan folder function
void MainWindow::loadSetting( const QString& appSettingPath,
                  const QString& captureSettingPath )
{
    m_appSetting.loadAppSetting(appSettingPath);
    m_captureSetting.loadCaptureSetting(captureSettingPath);
}

void MainWindow::scanJobFolder(const QString& path)
{
    QDir dir(path);
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step1:判断文件夹是否存在，不存在则创建
    if(!dir.exists())
    {
        std::cout << path.toStdString() << " is not exists!"<< std::endl;
        bool isCreatedPath = dir.mkpath(path);
        //文件夹不存在，判断是否创建成功，不成功则抛出异常
        if( !isCreatedPath )
        {
            THROW_EXCEPTION("Path is not existed and create path error!");
        }
    }
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //step2:扫描检测程式
    QStringList filters;    //创建过滤器列表，过滤xml、txt为后缀的文件
    filters << "*[^xml|^txt]";
    dir.setNameFilters(filters);

    dir.setFilter(QDir::Files);
    QFileInfoList list = dir.entryInfoList();
    //没有要读取的程式文件，向程式中写入默认数据
    if ( 0 == list.size() )
    {
        int chipCnt {20};
        int icCnt {30};
        generateObjsRandomly(chipCnt,icCnt);
        m_inspectionData.print();

        QString tempPath {path};
        QString dbPath = tempPath.append("iPhoneV1");
        m_inspectionData.writeToDB(dbPath.toStdString());
//        tempPath = path;
//        QString xmlPath = tempPath.append("iPhoneV1.xml");
//        m_inspectionData.writeToXml(xmlPath);
    }
    else
    {
        //将扫描的文件打印在终端上
        for (int i = 0; i < list.size(); ++i)
        {
            std::cout << qPrintable( QString("%1:%2\n").arg(i+1).arg(list.at(i).fileName()) );
        }
        int index {0};
        //选择需要读取的检查程式文件
        do
        {
            std::cout << "\nPlease choice the file!(1-" << list.size() << ")\n";
            std::cin >> index;
            //判断输入是否为数字
            if(!std::cin)
            {
                std::cout << "Error! Not a digit!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                index = 0;
            }
        }
        while( index > list.size() || index <= 0);
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        // step3:读取用户选择的文件,并输出为xml文件
        QString dbPath = list.at(index-1).filePath();
        m_inspectionData.readFromDB(dbPath.toStdString());
        m_inspectionData.print();
        QString xmlPath = dbPath.append(".xml");
        m_inspectionData.writeToXml(xmlPath);
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//generate data function
void MainWindow::generateObjsRandomly( int chipCnt, int icCnt )
{

    double minPosX {0};
    double maxPosX {10};
    double minPosY {0};
    double maxPosY {10};
    double minWidth {90};
    double maxWidth {110};
    double minHeight {90};
    double maxHeight {110};

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1.默认的版本和当前编辑时间
    auto time = std::time(nullptr);
    m_inspectionData.setVersion("V1");
    m_inspectionData.setEditingTime(asctime(localtime (&time)));

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2.默认的job程式名,原点位置,尺寸大小
    this->m_inspectionData.board().setName("iPhoneV1");
    this->m_inspectionData.board().setOriginalX(0.00);
    this->m_inspectionData.board().setOriginalY(0.00);
    this->m_inspectionData.board().setSizeX(200.00);
    this->m_inspectionData.board().setSizeY(200.00);

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3.生成随机数据

    std::stringstream rectNameSteam;
    Job::MeasuredObj* pMeasureObj = nullptr;
    for ( int i = 1; i <= chipCnt+icCnt; ++i )
    {
        pMeasureObj = new Job::MeasuredObj();
        if ( i <= chipCnt )
        {
            rectNameSteam<<"chip_"<<std::setfill('0')<<std::setw(3)<<i;
        }
        else
        {
            rectNameSteam<<"ic_"<<std::setfill('0')<<std::setw(3)<<i-chipCnt;
        }
        pMeasureObj->setName(rectNameSteam.str());
        pMeasureObj->body().setPosX(RANDOM_DIGIT(minPosX,maxPosX));
        pMeasureObj->body().setPosY(RANDOM_DIGIT(minPosY,maxPosY));
        pMeasureObj->body().setWidth(RANDOM_DIGIT(minWidth,maxWidth));
        pMeasureObj->body().setHeight(RANDOM_DIGIT(minHeight,maxHeight));

        this->m_inspectionData.board().measuredList().pushBack(*pMeasureObj);
        rectNameSteam.str("");
    }
    pMeasureObj = nullptr;
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------








