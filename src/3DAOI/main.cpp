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

//    SDK::Rectangle pad1(0,0,100,100);
//    SDK::Rectangle pad2(1,1,101,101);
//    Job::MeasureObj measureObj1("chip_001",pad1);
//    Job::MeasureObj measureObj2("chip_002",pad2);

//    Job::MeasureList measureList;
//    measureList.pushBack(measureObj1);
//    measureList.pushFront(measureObj2);

//    measureList.print();
//    measureList.print();
//    measureList.pullBack();
//    measureList.print();
//    measureList.pullBack();
//    measureList.print();

//    measureList.clear();


    return 0;
}

