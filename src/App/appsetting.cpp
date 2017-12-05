#include "appsetting.hpp"

using namespace App;
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor
AppSetting::AppSetting()
{

}

AppSetting::~AppSetting()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load & read & write function
void AppSetting::loadAppSetting(const QString& path)
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

void AppSetting::readAppSetting(const QString& path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);
        if( 1 != QSettings::IniFormat)
        {
            //加载配置文件失败,抛出异常.
            THROW_EXCEPTION("Load ini file error!")
        }

        //加载公司名, 不正确就写入默认值
        QString name =  configFile.value("CompanyName").toString();
        if(name != "" )
        {
            this->m_companyName = name.toStdString();
        }
        else
        {   // 加载公司名失败,设置为默认公司Sung!
            configFile.setValue("CompanyName", "SciJet");
        }

        //加载机器名称, 不正确就写入默认值
        QString type =  configFile.value("MachineName").toString();
        if ( type.toUpper().toStdString() == VAR_TO_STR(MachineName::AOI) )
        {
            this->m_machineName = MachineName::AOI;
        }
        else if ( type.toUpper().toStdString() == VAR_TO_STR(MachineName::SPI) )
        {
            this->m_machineName = MachineName::SPI;
        }
        else
        {   // 加载机器类型失败,设置为默认机器类型AOI!
            configFile.setValue("MachineName","AOI");
        }

        //加载主题, 不正确就写入默认值
        QString theme =  configFile.value("Theme").toString();
        if ( theme.toUpper().toStdString() == VAR_TO_STR(Theme::BLACK) )
        {
            this->m_theme = Theme::BLACK;
        }
        else if ( theme.toUpper().toStdString() == VAR_TO_STR(Theme::WHITE) )
        {
            this->m_theme = Theme::WHITE;
        }
        else
        {   // 加载主题失败,设置默认主题White!
            configFile.setValue("Theme","white");
        }

        //加载语言,不正确就写入默认值
        QString language =  configFile.value("Language").toString();
        if ( language.toUpper().toStdString() == VAR_TO_STR(Language::CN) )
        {
            this->m_lang = Language::CN;
        }
        else if ( language.toUpper().toStdString() == VAR_TO_STR(Language::EN) )
        {
            this->m_lang = Language::EN;
        }
        else
        {   //加载语言失败,设置默认语言EN!
            configFile.setValue("Language", "EN");
        }

        //加载机器类型,不正确就写入默认值
        QString mode =  configFile.value("LaneMode").toString();
        if ( mode.toUpper().toStdString() == VAR_TO_STR(LaneMode::SIMULATOR) )
        {
            this->m_laneMode = LaneMode::SIMULATOR;
        }
        else if ( mode.toUpper().toStdString() == VAR_TO_STR(LaneMode::SINGLE_LANE) )
        {
            this->m_laneMode = LaneMode::SINGLE_LANE;
        }
        else if ( mode.toUpper().toStdString() == VAR_TO_STR(LaneMode::DUAL_LANE) )
        {
            this->m_laneMode = LaneMode::DUAL_LANE;
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

void AppSetting::writeAppSetting(const QString &path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);
        if( 1 != QSettings::IniFormat)
        {
            THROW_EXCEPTION("Load ini file error!")
        }
        // 配置文件不存在,创建默认值配置文件
        configFile.setValue("CompanyName", "SciJet");
        configFile.setValue("MachineName", "AOI");
        configFile.setValue("Theme", "white");
        configFile.setValue("Language", "EN");
        configFile.setValue("LaneMode", "DualLane");
    }
    catch ( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what());
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



