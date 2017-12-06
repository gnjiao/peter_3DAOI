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
    try
    {
        App::MainWindow appStart;

        // 加载配置文件
        appStart.loadSetting( APP_SETTING_PATH,CAPTURE_SETTING_PATH );

        // 扫描程式文件夹下是否有程式文件
        appStart.scanJobFolder(JOB_FOLDER_PATH );

        // 在屏幕上打印程式信息
        appStart.inspectionData().print();
    }
    catch ( SDK::CustomException& ex)
    {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}

