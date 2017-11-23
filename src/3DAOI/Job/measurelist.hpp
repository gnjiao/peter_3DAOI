#ifndef MEASURELIST_HPP
#define MEASURELIST_HPP

#include <iostream>

#include "measureobj.hpp"

namespace Job
{
    /**
     *  @brief MeasureList
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class MeasureList
    {
    public:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor
        MeasureList();
        ~MeasureList();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // size & isEmpty & clear &print function
        int size();
        bool isEmpty();
        void clear();
        void print();

        // push & pull function
        void pushBack(MeasureObj measureObj);
        void pushFront(MeasureObj measureObj);
        bool pullBack();
        bool pullFront();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_size;
        MeasureObj* m_pHead;
        MeasureObj* m_pTail;
    };
}//End of Job

#endif // MEASURELIST_HPP

