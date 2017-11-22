#ifndef MEASURELIST_HPP
#define MEASURELIST_HPP

#include <iostream>

#include "measureobj.hpp"

namespace Job
{
    class MeasureList
    {
    public:
        MeasureList();
        ~MeasureList();

    private:
        MeasureObj* m_head;
        MeasureList* m_tail;
    };
}

#endif // MEASURELIST_HPP
