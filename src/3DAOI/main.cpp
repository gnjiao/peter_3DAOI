#include <iostream>

#include <QString>


#include "./App/appsetting.hpp"
#include "./App/capturesetting.hpp"
#include "./SDK/rectangle.hpp"
#include "./SDK/customexception.hpp"


#define APP_SETTING "../AppSetting.ini"
#define CAPTURE_SETTING "../CaptureSetting.ini"

using namespace std;

int main()
{
    App::AppSetting mm;
    mm.loadAppSetting(APP_SETTING);

//    App::CaptureSetting nn;
//    nn.loadCaptureSetting(CAPTURE_SETTING);

//    VAR_TO_STR(App::AppSetting::MachineName::AOI);

    return 0;
}

