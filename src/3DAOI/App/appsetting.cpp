#include "appsetting.hpp"

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

App::AppSetting::AppSetting()
{

}

App::AppSetting::~AppSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load & read & write function

void App::AppSetting::loadAppSetting(const QString &path)
{
    try
    {
        if( !QFile::exists(path) )
        {   //路径不存在, 新建一个配置文件, 参数使用默认值
            writeAppSetting(path);
        }
        else
        {   //路径存在,读取配置文件
            readAppSetting(path);
        }
    }
    catch( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what());
    }
}

void App::AppSetting::readAppSetting(const QString &path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);
        if( 1 != QSettings::IniFormat)
        {
            THROW_EXCEPTION("Load ini file error!")
        }

        //加载公司名, 如果不正确的话就写入默认值
        QString name =  configFile.value("CompanyName").toString();
        if(name == "Sung" || name == "SciJet")
        {
            this->m_companyName = name.toStdString();
        }
        else
        {   // 加载公司名失败,设置为默认公司Sung!
            configFile.setValue("CompanyName", "SciJet");
        }

        //加载机器类型, 如果不正确的话就写入默认值
        QString type =  configFile.value("MachineName").toString();
        if ( type.toUpper().toStdString() == VAR_TO_STR(AOI) )
        {
            this->m_companyName = MachineName::AOI;
        }
        else if ( type.toUpper().toStdString() == VAR_TO_STR(SPI) )
        {
            this->m_companyName = MachineName::SPI;
        }
        else
        {   // 加载机器类型失败,设置为默认机器类型AOI!
            configFile.setValue("MachineName","AOI");
        }

        //加载主题, 如果不正确的话就写入默认值
        QString theme =  configFile.value("Theme").toString();
        if ( theme.toUpper().toStdString() == VAR_TO_STR(BLACK) )
        {
            this->m_theme = Theme::BLACK;
        }
        else if ( theme.toUpper().toStdString() == VAR_TO_STR(WHITE) )
        {
            this->m_theme = Theme::WHITE;
        }
        else
        {   // 加载主题失败,设置默认主题White!
            configFile.setValue("Theme","white");
        }

        //加载语言,如果不正确的话就写入默认值
        QString language =  configFile.value("Language").toString();
        if ( language.toUpper().toStdString() == VAR_TO_STR(CN) )
        {
            this->m_lang = Language::CN;
        }
        else if ( language.toUpper().toStdString() == VAR_TO_STR(EN) )
        {
            this->m_lang = Language::EN;
        }
        else
        {   //加载语言失败,设置默认语言EN!
            configFile.setValue("Language", "EN");
        }

        //加载轨道模式,如果不正确的话就写入默认值
        QString mode =  configFile.value("LaneMode").toString();
        if ( mode.toUpper().toStdString() == VAR_TO_STR(SIMULATOR) )
        {
            this->m_laneMode = LaneMode::SIMULATOR;
        }
        else if ( mode.toUpper().toStdString() == VAR_TO_STR(SINGLELANE) )
        {
            this->m_laneMode = LaneMode::SINGLELANE;
        }
        else if ( mode.toUpper().toStdString() == VAR_TO_STR(DUALLANE) )
        {
            this->m_laneMode = LaneMode::DUALLANE;
        }
        else
        {   //加载轨道模式失败,设置默认轨道模式DualLane!
            configFile.setValue("LaneMode", "DualLane");
        }
    }
    catch(const SDK::CustomException& ex)
    {
        THROW_EXCEPTION(ex.what());
    }
}

void App::AppSetting::writeAppSetting(const QString &path)
{
    QSettings configFile(path, QSettings::IniFormat);

    // 配置文件不存在,创建默认值配置文件
    configFile.setValue("CompanyName", "SciJet");
    configFile.setValue("MachineName", "AOI");
    configFile.setValue("Theme", "white");
    configFile.setValue("Language", "EN");
    configFile.setValue("LaneMode", "DualLane");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



