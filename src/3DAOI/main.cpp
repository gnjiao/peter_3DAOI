#include <iostream>

#include <QString>

#include "./App/appsetting.hpp"
#include "./App/capturesetting.hpp"
#include "./App/appstart.hpp"
#include "./SDK/rectangle.hpp"
#include "./SDK/customexception.hpp"
#include "./Job/measureobj.hpp"
#include "./Job/measurelist.hpp"

#define APP_SETTING_PATH "../AppSetting.ini"
#define CAPTURE_SETTING_PATH "../CaptureSetting.ini"
#define JOB_FOLDER_PATH "../data"

using namespace std;

int main()
{

    App::AppStart appStart;

    appStart.loadSetting( APP_SETTING_PATH,
                          CAPTURE_SETTING_PATH );
    appStart.scanJobFolder(JOB_FOLDER_PATH);



    return 0;
}

