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
        App::MainWindow mainWindow;

        // 加载配置文件
        mainWindow.loadSetting( APP_SETTING_PATH,CAPTURE_SETTING_PATH );

        // 加载用户选择的程式文件
        mainWindow.loadJobFolder(JOB_FOLDER_PATH );

        // 在屏幕上打印程式信息
        mainWindow.inspectionData().print();

    }
    PRINT_EXCEPTION();

    return 0;
}

