#include <iostream>

#include <QString>

#include "./App/appsetting.hpp"
#include "./App/capturesetting.hpp"
#include "./App/mainWindow.hpp"

#define APP_SETTING_PATH "../AppSetting.ini"
#define CAPTURE_SETTING_PATH "../CaptureSetting.ini"
#define JOB_FOLDER_PATH "../data/"

using namespace std;

int main()
{

    App::MainWindow appStart;

    appStart.loadSetting( APP_SETTING_PATH,CAPTURE_SETTING_PATH );
    appStart.scanJobFolder(JOB_FOLDER_PATH );

    return 0;
}

