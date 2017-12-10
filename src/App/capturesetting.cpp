#include "capturesetting.hpp"

using namespace App;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

CaptureSetting::CaptureSetting()
{
    int defaultImageWidth = 3072;   // 默认图像面阵宽度
    int defaultImageHeight = 4096;  // 默认图像面阵高度

    this->m_imageWidth = defaultImageWidth;
    this->m_imageHeight = defaultImageHeight;
    this->m_imageBit = ImageBit::BIT8;
}

CaptureSetting::~CaptureSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load & read function

void CaptureSetting::loadCaptureSetting( const QString& path )
{
    try
    {
        if( !QFile::exists(path) )
        {   // 配置文件不存在
            THROW_EXCEPTION("No CaptureSetting.ini file!");
        }
        else
        {   // 配置文件存在,读取配置文件
            readCaptureSetting(path);
        }
    }
    catch( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION( ex.what() );
    }
}

void CaptureSetting::readCaptureSetting( const QString& path )
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);
        if( 1 != QSettings::IniFormat)
        {
            // 加载配置文件失败,抛出异常.
            THROW_EXCEPTION("Load CaptureSetting.ini file error!")
        }

        //>>>-------------------------------------------------------------------
        // 1.加载图像位数
        QString imgBit =  configFile.value("ImageBits").toString();
        if ( imgBit.toUpper().toStdString() == VAR_TO_STR(ImageBit::BIT8) )
        {
            this->m_imageBit = ImageBit::BIT8;
        }
        else if ( imgBit.toUpper().toStdString() == VAR_TO_STR(ImageBit::BIT16) )
        {
            this->m_imageBit = ImageBit::BIT16;
        }
        else
        {
            // 图像位数不是8位或16位,抛出异常.
            THROW_EXCEPTION( "Image bit error in CaptureSetting.ini!" );
        }

        //>>>-------------------------------------------------------------------
        // 2.加载图像面阵高度
        int imgWidth =  configFile.value("ImageWidth").toInt();

        //>>>-------------------------------------------------------------------
        // 3.加载图像面阵宽度
        int imgHeight = configFile.value("ImageHeight").toInt();

        if( this->m_imageWidth != imgWidth ||
            this->m_imageHeight != imgHeight )
        {
            // 图像面阵宽度或高度不正确,抛出异常.
            THROW_EXCEPTION( "Image width or height error in CaptureSetting.ini!" );
        }
    }
    CATCH_AND_RETHROW_EXCEPTION("Catch exception and rethrow");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



