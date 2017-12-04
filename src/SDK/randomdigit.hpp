#ifndef RANDOMDIGIT_HPP
#define RANDOMDIGIT_HPP

#include <iostream>
#include <random>



namespace SDK
{
#define RANDOM_DIGIT(min,max)\
({\
    std::random_device rd;\
    std::default_random_engine gen = std::default_random_engine(rd());\
    std::uniform_real_distribution<double> dis(min,max);\
    dis(gen);\
})
//    #define RANDOM_DIGIT(min,max) (double)(rand()%(100*(int)(max-min)+1))/100 + (int)min
}//End of namespace SDK

#endif // RANDOMDIGIT_HPP

