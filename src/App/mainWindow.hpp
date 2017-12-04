#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <string>
#include <iomanip>
//#include <ctime>

#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QString>

#include "appsetting.hpp"
#include "capturesetting.hpp"
#include "../SDK/randomdigit.hpp"
#include "../Job/measuredlist.hpp"
#include "../Job/inspectiondata.hpp"

namespace App
{
    class MainWindow
    {
    public:
        MainWindow();
        virtual~MainWindow();

        void loadSetting( const QString& appSettingPath,
                          const QString& captureSettingPath );
        void scanJobFolder(const QString& path);

    private:
        void generateObjsRandomly(int chipCnt,int icCnt);

    private:
        App::AppSetting m_appSetting;
        App::CaptureSetting m_captureSetting;

        Job::InspectionData m_inspectionData;
    };
}//End of namespace App


#endif // APPLICATION_HPP
