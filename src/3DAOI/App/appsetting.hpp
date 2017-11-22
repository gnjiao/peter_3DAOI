#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>

#include <QSettings>
#include <QFile>

#include "../SDK/customexception.hpp"

//std::string MachineName[2] = {"AOI","SPI"};
//std::string Theme[2] = {"BLACK","WHITE"};
//std::string Lane[2] = {"EN","CN"};
//std::string LaneMode[3] = {"SIMULATOR","SINGLELANE","DUALLANE"};

namespace App
{
    class AppSetting
    {
    public:
        AppSetting();
        ~AppSetting();

        void loadAppSetting(const QString& path);
        void readAppSetting(const QString& path);
        void writeAppSetting(const QString& path);

    private:
        std::string m_companyName;
        enum MachineName {AOI,SPI};
        enum Theme {BLACK,WHITE};
        enum Lang {EN,CN};
        enum LaneMode {SIMULATOR,SINGLELANE,DUALLANE};

    };
}


#endif //APPSETTING_HPP
