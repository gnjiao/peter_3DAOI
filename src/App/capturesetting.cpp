#include "capturesetting.hpp"

using namespace App;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor
CaptureSetting::CaptureSetting()
{

}

CaptureSetting::~CaptureSetting()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load & read function
void CaptureSetting::loadCaptureSetting(const QString& path)
{
    try
    {
        if( !QFile::exists(path) )
        {   // 配置文件不存在
            THROW_EXCEPTION("No CaptureSetting.ini!");
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

void CaptureSetting::readCaptureSetting(const QString& path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);

        // 加载图像位数
        QString imgBit =  configFile.value("ImageBits").toString();
        if ( imgBit.toUpper().toStdString() == VAR_TO_STR(IMAGE_BIT::BIT8) )
        {
            this->m_imageBit = IMAGE_BIT::BIT8;
        }
        else if ( imgBit.toUpper().toStdString() == VAR_TO_STR(IMAGE_BIT::BIT16) )
        {
            this->m_imageBit = IMAGE_BIT::BIT16;
        }
        else
        {
            THROW_EXCEPTION("Capture setting error!");
        }
        // 加载图像高度
        int imgWidth =  configFile.value("ImageWidth").toInt();
        // 加载图像宽度
        int imgHeight = configFile.value("ImageHeight").toInt();

        if( this->m_imageWidth != imgWidth ||
            this->m_imageHeight != imgHeight )
        {
            THROW_EXCEPTION("Capture setting error!");
        }
    }
    catch( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what());
    }
}


void writeCaptureSetting(const QString& path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);
        if( 1 != QSettings::IniFormat)
        {
            THROW_EXCEPTION("Load ini file error!")
        }
        // 配置文件不存在,创建默认值配置文件
        configFile.setValue("ImageWidth", "100");
        configFile.setValue("ImageHeight", "100");
        configFile.setValue("ImageBits", "8");
    }
    catch ( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what());
    }

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



