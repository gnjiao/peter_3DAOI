#include <iostream>

#include <QString>



#include "./App/appsetting.hpp"
#include "./App/capturesetting.hpp"
#include "./SDK/rectangle.hpp"
#include "./SDK/customexception.hpp"
#include "./Job/measureobj.hpp"
#include "./Job/measurelist.hpp"

#define APP_SETTING "../AppSetting.ini"
#define CAPTURE_SETTING "../CaptureSetting.ini"

using namespace std;

int main()
{

    SDK::Rectangle pad1(0,0,100,100);
    SDK::Rectangle pad2(1,1,122,122);

    Job::MeasureObj chip1("chip_01",pad1);
    Job::MeasureObj chip2("chip_02",pad1);
    Job::MeasureObj chip3("chip_03",pad2);
    Job::MeasureObj chip4("chip_04",pad2);

    Job::MeasureList board;

    board.pushFront(chip1);
    board.pushFront(chip2);
    board.pushFront(chip3);
    board.pushFront(chip4);
    board.pushBack(chip1);
    board.pushBack(chip2);
    board.pushBack(chip3);
    board.pushBack(chip4);

    board.print();
    std::cout<<"---------------------------------------"<<std::endl;
    board.clear();

//    App::CaptureSetting nn;
//    nn.loadCaptureSetting(CAPTURE_SETTING);


    return 0;
}

