#include <iostream>

#include <QSettings>
#include <QFile>

#include "./SDK/customexception.hpp"

using namespace std;

void testEx()
{
    try
    {
        if( 1)
        {
            THROW_EXCEPTION("5>1\n");
        }
    }
    catch(const SDK::CustomException& ex)
    {
        cout << ex.what()<<endl;
    }
}

int main()
{
    testEx();
    cout << "Hello World!" << endl;
    return 0;
}
