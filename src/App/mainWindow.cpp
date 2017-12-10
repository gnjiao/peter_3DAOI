#include "mainWindow.hpp"

using namespace App;
using namespace Job;
using namespace SDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

MainWindow::MainWindow()
{

}

MainWindow::~MainWindow()
{
    MeasuredObj * pTmpObj = this->m_inspectionData.board().measuredList().pHead();
    while ( nullptr !=  pTmpObj )
    {
        pTmpObj = this->m_inspectionData.board().measuredList().pHead()->pNext();
        delete this->m_inspectionData.board().measuredList().pHead();
        this->m_inspectionData.board().measuredList().setHead(pTmpObj);
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load configure & load folder function

void MainWindow::loadSetting( const QString& appSettingPath,
                              const QString& captureSettingPath )
{
    try
    {
        m_appSetting.loadAppSetting(appSettingPath);
        m_captureSetting.loadCaptureSetting(captureSettingPath);
    }
    CATCH_AND_RETHROW_EXCEPTION("Catch exception and rethrow");
}

void MainWindow::loadJobFolder(const QString& jobFolderPath)
{
    QDir dir(jobFolderPath);
    try
    {
        //>>>-------------------------------------------------------------------
        // step1:判断文件夹是否存在，不存在则创建
        if(!dir.exists())
        {
            std::cout << jobFolderPath.toStdString() << " is not exists!"<< std::endl;
            // 文件夹不存在，判断是否创建成功，不成功则抛出异常
            if( !dir.mkpath(jobFolderPath) )
            {
                // 创建配置文件失败,抛出异常
                THROW_EXCEPTION("Create Job path error!");
            }
        }
        //>>>-------------------------------------------------------------------
        // step2:扫描检测程式
        QStringList filters;    // 创建过滤器列表，过滤xml、txt为后缀的文件
        filters << "*[^xml|^txt]";
        dir.setNameFilters(filters);

        dir.setFilter(QDir::Files);
        QFileInfoList list = dir.entryInfoList();
        // 没有要读取的程式文件，向程式中写入默认数据
        if ( 0 == list.size() )
        {
            int chipCnt {20};
            int icCnt {30};
            generateObjsRandomly(chipCnt,icCnt);

            QString dbPath {jobFolderPath};
            dbPath = dbPath.append("iPhoneV2");
            m_inspectionData.writeToDB(dbPath);
        }
        else
        {
            // 将扫描的文件打印在终端上
            for (int i = 0; i < list.size(); ++i)
            {
                std::cout << qPrintable( QString("%1:%2\n").arg(i+1).arg(list.at(i).fileName()) );
            }
            int index {0};
            // 选择需要读取的检查程式文件
            do
            {
                std::cout << "\nPlease choice the file!(1-" << list.size() << ")\n";
                std::cin >> index;
                // 判断输入是否为数字
                if(!std::cin)
                {
                    std::cout << "Error! Not a digit!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    index = 0;
                }
            }
            while( index > list.size() || index <= 0);
            //>>>---------------------------------------------------------------
            // step3:读取用户选择的文件
            QString dbPath = list.at(index-1).filePath();
            m_inspectionData.readFromDB(dbPath);
            // 输出到xml文件中
            QString xmlPath = dbPath.append(".xml");
            m_inspectionData.writeToXml(xmlPath);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION("Catch exception and rethrow");
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// generate data function
void MainWindow::generateObjsRandomly( int chipCnt, int icCnt )
{
    double boardSize = 100;                // 基板长宽均为100mm
    double boardMargin = 3;                // 板子边缘距离(板边距离检测对象的距离)
    double minSize = 1,maxSize = 10,size;  // 检测对象尺寸,最小值为1,最大值为10
    double minAngle = 0,maxAngle = 360,angle;   //检测对象的角度最大值与最小值
    double posX,posY,minPos,maxPos;        // 检测对象坐标值
    int precision = 2;                     // 小数点后的精度位数

    //>>>-----------------------------------------------------------------------
    // 1.默认的版本和当前编辑时间
    m_inspectionData.setVersion("V2");
    auto currentTime = std::time(nullptr);
    auto formatTime = *std::localtime(&currentTime);

    std::ostringstream timeStream;
    timeStream << std::put_time(&formatTime, "%Y-%m-%d %H:%M:%S");
    m_inspectionData.setEditingTime(timeStream.str());

    //>>>-----------------------------------------------------------------------
    // 2.默认的job程式名,原点位置,尺寸大小
    this->m_inspectionData.board().setName("iPhone");
    this->m_inspectionData.board().setOriginalX(0.00);
    this->m_inspectionData.board().setOriginalY(0.00);
    this->m_inspectionData.board().setSizeX(200.00);
    this->m_inspectionData.board().setSizeY(200.00);

    //>>>-----------------------------------------------------------------------
    // 3.生成随机数据

    std::stringstream rectNameSteam;
    MeasuredObj* pMeasureObj = nullptr;
    for ( int i = 1; i <= chipCnt+icCnt; ++i )
    {
        pMeasureObj = new MeasuredObj();
        if ( i <= chipCnt )
        {
            rectNameSteam<<"chip_"<<std::setfill('0')<<std::setw(3)<<i;
        }
        else
        {
            rectNameSteam<<"ic_"<<std::setfill('0')<<std::setw(3)<<i-chipCnt;
        }

        size = RandomDigit::randomDigit(precision,minSize,maxSize);
        minPos = size/2 + boardMargin;
        maxPos = boardSize - boardMargin - size/2;
        posX = RandomDigit::randomDigit(precision,minPos,maxPos);
        posY = RandomDigit::randomDigit(precision,minPos,maxPos);
        angle = RandomDigit::randomDigit(precision,minAngle,maxAngle);

        pMeasureObj->setName(rectNameSteam.str());
        pMeasureObj->body().setPosX(posX);
        pMeasureObj->body().setPosY(posY);
        pMeasureObj->body().setAngle(angle);
        pMeasureObj->body().setWidth(size);
        pMeasureObj->body().setHeight(size);

        this->m_inspectionData.board().measuredList().pushBack(*pMeasureObj);
        rectNameSteam.str("");
    }
    pMeasureObj = nullptr;
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------








