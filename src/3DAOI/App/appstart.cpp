#include "appstart.hpp"

App::AppStart::AppStart()
{

}

App::AppStart::~AppStart()
{

}

void App::AppStart::loadSetting( const QString& appSettingPath,
                                 const QString& captureSettingPath )
{
    m_appSetting.loadAppSetting(appSettingPath);
    m_captureSetting.loadCaptureSetting(captureSettingPath);
}

void App::AppStart::scanJobFolder(const QString& path)
{
    QDir dir {path};

    //step1:判断文件夹是否存在，不存在则创建
    if(!dir.exists())
    {
        std::cout << path.toStdString() << " is not exists!"
                  << std::endl;
        bool isCreatedPath = dir.mkpath(path);
        //文件夹不存在，判断是否创建成功，不成功则抛出异常
        if( !isCreatedPath )
        {
            THROW_EXCEPTION("Path is not exits and create path error!");
        }
    }

    //step2:扫描检测程式
    QStringList filters;//创建过滤器列表，过滤xml为后缀的文件
    filters << "*[^x][^m][^l]";
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
            std::cout << qPrintable( QString("%1:%2")
                                     .arg(i+1)
                                     .arg(list.at(i).fileName()) );
            std::cout << std::endl;
        }
        int index {0};
        //选择需要读取的检查程式文件
        do
        {
            std::cout << std::endl

                      << "Please choice the file!(1-" << list.size() << ")"
                      << std::endl;
            std::cin >> index;

            if(!std::cin)
            {
                std::cout << "Error! not a digit!"
                          << std::endl;
                std::cin.clear();
                std::cin.ignore();
                index = 0;
            }

        }while( index > list.size() || index <= 0);

        //step3:读取用户选择的文件,并输出为xml文件
        QString file = list.at(index-1).filePath();
//        readInspectionData(file);
//        writeToXml(file);
    }
}

