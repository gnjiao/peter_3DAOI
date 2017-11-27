#ifndef MEASURELIST_HPP
#define MEASURELIST_HPP

#include <iostream>

#include "measureobj.hpp"
#include "../SDK/customexception.hpp"

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
        /**
         *  @brief MeasureList
         *      默认构造函数
         *  @param N/A
         *  @return N/A
         */
        MeasureList();
        ~MeasureList();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // size & isEmpty & clear &print function
        int size(){return m_size;}
        bool isEmpty(){return 0==m_size?true:false;}
        void clear();
        void print();

        // push & pull function
        void pushBack(MeasureObj measureObj);
        void pushFront(MeasureObj measureObj);
        void pullBack();
        void pullFront();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_size {0};
        MeasureObj* m_pHead = nullptr;
        MeasureObj* m_pTail = nullptr;
    };
}//End of Job

#endif // MEASURELIST_HPP

