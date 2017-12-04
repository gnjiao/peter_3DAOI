#ifndef RANDOMDIGIT_HPP
#define RANDOMDIGIT_HPP

//#include <time.h>

namespace SDK
{
    #define RANDOM_DIGIT(min,max) (double)(rand()%(100*(int)(max-min)+1))/100 + (int)min
}//End of namespace SDK

#endif // RANDOMDIGIT_HPP
