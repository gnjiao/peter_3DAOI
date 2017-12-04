#ifndef MEASUREDLIST_HPP
#define MEASUREDLIST_HPP

#include <iostream>
#include <iomanip>

#include "measuredobj.hpp"
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
    class MeasuredList
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
        MeasuredList();
        ~MeasuredList();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //set & get function
        MeasuredObj* pHead(){return this->m_pHead;}
        void setHead(MeasuredObj* pHead){this->m_pHead = pHead;}

        MeasuredObj* pTail(){return this->m_pTail;}
        void setTail(MeasuredObj* pTail){this->m_pTail = pTail;}
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // size & isEmpty & clear &print function
        int size(){return m_size;}
        bool isEmpty(){return 0==m_size?true:false;}
        void clear();
        void print();

        // push & pull function
        void pushBack(MeasuredObj& measureObj);
        void pushFront(MeasuredObj& measureObj);
        void pullBack();
        void pullFront();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_size {0};
        MeasuredObj* m_pHead {nullptr};
        MeasuredObj* m_pTail {nullptr};
    };
}//End of namespace Job

#endif // MEASUREDLIST_HPP

