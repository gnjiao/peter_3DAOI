#include <iostream>

#include "./SDK/rectangle.hpp"
#include "./SDK/customexception.hpp"
#include "./App/appsetting.hpp"

#define APP_SETTING "../AppSetting.ini"

using namespace std;

int main()
{
    App::AppSetting mm;
    mm.readAppSetting(APP_SETTING);

    cout << "Hello World!" << endl;
    return 0;
}
