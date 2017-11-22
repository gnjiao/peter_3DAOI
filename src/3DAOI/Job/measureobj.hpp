#ifndef MEASUREOBJ_HPP
#define MEASUREOBJ_HPP

#include <iostream>

#include "../SDK/rectangle.hpp"

namespace Job
{
    class MeasureObj
    {
    public:
        std::string m_name;
        SDK::Rectangle m_body;
        MeasureObj* m_pPre;
        MeasureObj* m_pNext;
        MeasureObj( std::string name,
                    SDK::Rectangle& body,
                    MeasureObj* pPre=NULL,
                    MeasureObj* pNext=NULL );
    };
}

#endif // MEASUREOBJ_HPP
