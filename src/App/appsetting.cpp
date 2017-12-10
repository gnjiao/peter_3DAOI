#include "appsetting.hpp"

using namespace App;
using namespace SDK;
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

AppSetting::AppSetting()
{
    this->m_companyName = "SciJet";
    this->m_machineName = MachineName::AOI;
    this->m_theme = Theme::WHITE;
    this->m_lang = Language::EN;
    this->m_laneMode = LaneMode::DUAL_LANE;
}

AppSetting::~AppSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// load & read & write function

void AppSetting::loadAppSetting(const QString& appSettingPath)
{
    try
    {
        if( !QFile::exists(appSettingPath) )
        {
            // 文件不存在, 新建一个配置文件, 参数使用默认值
            writeAppSetting(appSettingPath);
        }
        else
        {
            // 文件存在,读取配置文件
            readAppSetting(appSettingPath);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION("Catch exception and rethrow");
}

void AppSetting::readAppSetting(const QString& appSettingPath)
{
    try
    {
        QSettings configFile(appSettingPath, QSettings::IniFormat);
        if( !configFile.isWritable() )
        {
            //加载配置文件失败,抛出异常.
            THROW_EXCEPTION("Load AppSetting file error!")
        }

        //>>>-------------------------------------------------------------------
        // 1.加载公司名, 不正确就写入默认值
        QString name =  configFile.value("CompanyName").toString();
        if(name != "" )
        {
            this->m_companyName = name.toStdString();
        }
        else
        {
            configFile.setValue("CompanyName",QString::fromStdString(m_companyName));
        }
        //>>>-------------------------------------------------------------------
        // 2.加载机器名称, 不正确就写入默认值
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
        {
            configFile.setValue( "MachineName",
                                 QString::fromStdString(VAR_TO_STR(MachineName::AOI)) );
        }
        //>>>-------------------------------------------------------------------
        // 3.加载主题, 不正确就写入默认值
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
        {
            configFile.setValue( "Theme",
                                 QString::fromStdString(VAR_TO_STR(Theme::BLACK)) );
        }
        //>>>-------------------------------------------------------------------
        //4.加载语言,不正确就写入默认值
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
        {
            configFile.setValue( "Language",
                                  QString::fromStdString(VAR_TO_STR(Language::EN)) );
        }
        //>>>-------------------------------------------------------------------
        // 5.加载机器类型,不正确就写入默认值
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
        {
            configFile.setValue( "LaneMode",
                                 QString::fromStdString(VAR_TO_STR(LaneMode::DUAL_LANE)) );
        }
    }
    CATCH_AND_RETHROW_EXCEPTION("Catch exception and rethrow");
}

void AppSetting::writeAppSetting( const QString& appSettingPath )
{
    try
    {
        QSettings configFile(appSettingPath, QSettings::IniFormat);

        if( !configFile.isWritable() )
        {
            THROW_EXCEPTION("Create AppSetting error!");
        }
        // 配置文件不存在,创建默认值配置文件
        configFile.setValue( "CompanyName",
                             QString::fromStdString(m_companyName) );
        configFile.setValue( "MachineName",
                             QString::fromStdString(VAR_TO_STR(MachineName::AOI)) );
        configFile.setValue( "Theme",
                             QString::fromStdString(VAR_TO_STR(Theme::BLACK)) );
        configFile.setValue( "Language",
                              QString::fromStdString(VAR_TO_STR(Language::EN)) );
        configFile.setValue( "LaneMode",
                             QString::fromStdString(VAR_TO_STR(LaneMode::DUAL_LANE)) );

    }
    CATCH_AND_RETHROW_EXCEPTION("Catch exception and rethrow");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



