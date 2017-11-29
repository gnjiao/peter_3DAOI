#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QString>

#include "appsetting.hpp"
#include "capturesetting.hpp"

namespace App
{
    class AppStart
    {
    public:
        AppStart();
        virtual~AppStart();

        void loadSetting( const QString& appSettingPath,
                          const QString& captureSettingPath );

        void scanJobFolder(const QString& path);

    private:
        AppSetting m_appSetting;
        CaptureSetting m_captureSetting;
        std::string m_jobFolderPath;

    };
}//End of namespace App


#endif // APPLICATION_HPP
