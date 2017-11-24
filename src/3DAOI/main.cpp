#include <iostream>

#include "./SDK/rectangle.hpp"
#include "./SDK/customexception.hpp"
#include "./Job/measureobj.hpp"
#include "./Job/measurelist.hpp"
#include "./App/appsetting.hpp"

#define APP_SETTING "../AppSetting.ini"

using namespace std;

int main()
{

    SDK::Rectangle pad(0,0,100,100);
    SDK::Rectangle pad2(1,1,122,122);

    Job::MeasureObj chip1("chip_01",pad);
    Job::MeasureObj chip2("chip_02",pad);
    Job::MeasureObj chip3("chip_03",pad2);
    Job::MeasureObj chip4("chip_04",pad2);

    Job::MeasureList board;

    board.pushBack(chip1);
    board.pushBack(chip2);
    board.pushBack(chip3);
    board.pushBack(chip4);
    board.pushFront(chip1);
    board.pushFront(chip2);
    board.pushFront(chip3);
    board.pushFront(chip4);
    std::cout<<"4321-1234"<<std::endl;

//   board.clear();

    board.pullFront();
//    board.print();
    std::cout<<"pullFront01"<<std::endl<<std::endl;

//    board.pullBack();
//    board.print();
//    std::cout<<"pullBack"<<std::endl<<std::endl;

//    board.pullBack();
//    board.print();
//    std::cout<<"pullBack"<<std::endl<<std::endl;

    board.pullFront();
//    board.print();
    std::cout<<"pullFront02"<<std::endl<<std::endl;



    cout << "Hello World!" << endl;
    return 0;
}
