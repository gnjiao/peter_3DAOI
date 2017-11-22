#include "appsetting.hpp"

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

App::AppSetting::AppSetting()
{
    this->m_companyName = "Sung";
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
        THROW_EXCEPTION("Unknown Error!");
    }
}

void App::AppSetting::readAppSetting(const QString &path)
{
    try
    {
        QSettings configFile(path, QSettings::IniFormat);

        //加载公司名, 如果不正确的话就写入默认值
        QString name =  configFile.value("CompanyName").toString();
        if(name != "Sung" && name != "SciJet")
        {   // 加载公司名失败,设置为默认公司Sung!
            configFile.setValue("CompanyName", "SciJet");
        }

        //加载机器类型, 如果不正确的话就写入默认值
        QString type =  configFile.value("MachineName").toString();
        if(type != "AOI" && type != "SPI")
        {   // 加载机器类型失败,设置为默认机器类型AOI!
            configFile.setValue("MachineName", "AOI");
        }


        //加载主题, 如果不正确的话就写入默认值
        QString theme =  configFile.value("Theme").toString();
        if(theme != "Black" && theme != "White")
        {    // 加载主题失败,设置默认主题White!
            configFile.setValue("Theme", "White");
        }

        //加载语言,如果不正确的话就写入默认值
        QString lang =  configFile.value("Lang").toString();
        if(lang != "CN" && lang != "EN")
        {
            // 加载语言失败,设置为默认语言CN!
            configFile.setValue("Lang", "EN");
        }

        //加载轨道模式,如果不正确的话就写入默认值
        QString mode =  configFile.value("LaneMode").toString();
        if( mode != "Simulators" &&
            mode != "Singlelane" &&
            mode != "Duallane" )
        {   // 加载轨道模式失败,设置默认值Simulators!
            configFile.setValue("LaneMode", "DualLane");
        }

    }
    catch(const SDK::CustomException& ex)
    {
        THROW_EXCEPTION("Unknown Error!");
    }
}

void App::AppSetting::writeAppSetting(const QString &path)
{
    QSettings configFile(path, QSettings::IniFormat);

    // 配置文件不存在,创建默认值配置文件
    configFile.setValue("CompanyName", "SciJet");
    configFile.setValue("MachineName", "AOI");
    configFile.setValue("Theme", "White");
    configFile.setValue("Lang", "EN");
    configFile.setValue("LaneMode", "DualLane");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



