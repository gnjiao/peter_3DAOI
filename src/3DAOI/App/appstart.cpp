#include "appstart.hpp"

using App::AppStart;

AppStart::AppStart()
{

}

AppStart::~AppStart()
{

}

void AppStart::loadSetting( const QString& appSettingPath,
                                 const QString& captureSettingPath )
{
    m_appSetting.loadAppSetting(appSettingPath);
    m_captureSetting.loadCaptureSetting(captureSettingPath);
}

void AppStart::scanJobFolder(const QString& path)
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
        //        writeInspectionData();
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
        QString file = list.at(index-1).filePath();
        //        readInspectionData(file);
        //        writeToXml(file);
    }
}

