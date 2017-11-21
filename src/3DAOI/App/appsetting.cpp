#include "appsetting.hpp"

App::AppSetting::AppSetting()
{

}

App::AppSetting::~AppSetting()
{

}

void App::AppSetting::loadAppSetting(const QString &path)
{
    try
    {
        if( !QFile::exists(path) )
        {
            //路径不存在, 新建一个配置文件, 参数使用默认值
            std::cout << "没有该配置文件, 使用默认配置!"
                      << std::endl;
            writeAppSetting(path);
        }
        else
        {
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
        {
            std::cout << "加载公司名失败,设置为默认公司Sung!"
                      << std::endl;
            configFile.setValue("CompanyName", "Sung");
        }
        else
        {
            std::cout << "加载公司名成功!"
                      << name.toStdString()
                      << std::endl;
        }

        //加载机器类型, 如果不正确的话就写入默认值
        QString type =  configFile.value("MachineName").toString();
        if(type != "AOI" && type != "SPI")
        {
            std::cout << "加载机器类型失败,设置为默认机器类型AOI!"
                      << std::endl;
            configFile.setValue("MachineName", "AOI");
        }
        else
        {
            std::cout << "加载机器类型成功!"
                      << type.toStdString()
                      << std::endl;
        }

        //加载主题, 如果不正确的话就写入默认值
        QString theme =  configFile.value("Theme").toString();
        if(theme != "Black" && theme != "White")
        {
            std::cout << "加载主题失败,设置默认主题White!"
                      << std::endl;
            configFile.setValue("Theme", "White");
        }
        else
        {
            std::cout << "加载主题成功!"
                      << theme.toStdString()
                      << std::endl;
        }

        //加载语言,如果不正确的话就写入默认值
        QString lang =  configFile.value("Lang").toString();
        if(lang != "CN" && lang != "EN")
        {
            std::cout << "加载语言失败,设置为默认语言CN!"
                      << std::endl;
            configFile.setValue("Lang", "CN");
        }
        else
        {
            std::cout << "加载语言成功!"
                      << lang.toStdString()
                      << std::endl;
        }

        //加载轨道模式,如果不正确的话就写入默认值
        QString mode =  configFile.value("LaneMode").toString();
        if( mode != "SIMULATOR" &&
            mode != "SINGLELANE" &&
            mode != "DUALLANE" )
        {
            std::cout << "加载轨道模式失败,设置默认值SIMUATOR!"
                      << std::endl;
            configFile.setValue("LaneMode", "SINGLELANE");
        }
        else
        {
            std::cout << "加载轨道模式成功!"
                      << mode.toStdString()
                      << std::endl;
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

    configFile.setValue("CompanyName", "SciJet");
    configFile.setValue("MachineName", "AOI");
    configFile.setValue("Theme", "White");
    configFile.setValue("Lang", "EN");
    configFile.setValue("LaneMode", "DualLane");
}
