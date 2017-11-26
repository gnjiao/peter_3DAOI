#include "capturesetting.hpp"


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

App::CaptureSetting::CaptureSetting()
{

}

App::CaptureSetting::CaptureSetting(int imageWidth,
                                    int imageHeitht,
                                    int imageBits)
{
    this->m_imageWidth = imageWidth;
    this->m_imageHeight = imageHeitht;
    this->m_imageBits = imageBits;
}

App::CaptureSetting::~CaptureSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load & read function

void App::CaptureSetting::loadCaptureSetting(const QString &path)
{
    try
    {
        if( !QFile::exists(path) )
        {   // 配置文件不存在
            THROW_EXCEPTION("No CaptureSetting.ini!")
        }
        else
        {   // 配置文件存在,读取配置文件
            readCaptureSetting(path);
        }
    }
    catch( const SDK::CustomException& ex )
    {
        std::cout << ex.what() << std::endl;
    }
}

void App::CaptureSetting::readCaptureSetting(const QString &path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);

        // 加载图像高度
        int imgWidth =  configFile.value("Image Width").toInt();
        // 加载图像宽度
        int imgHeight = configFile.value("Image Height").toInt();
        // 加载图像位数
        int imgBits = configFile.value("Image Bits").toInt();

        if( this->m_imageWidth != imgWidth ||
            this->m_imageHeight != imgHeight ||
            this->m_imageBits != imgBits )
        {
            printf("imgWidth:%d\n",imgWidth);
            THROW_EXCEPTION("Image configuare arguement error!");
        }
    }
    catch( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what());
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



