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
        /**
         * @brief ~MeasuredList
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual~MeasuredList();
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
        /**
         * @brief size
         *      获得链表长度
         * @param N/A
         * @return
         *      返回链表长度,类型为整型
         */
        int size(){return m_size;}
        /**
         * @brief isEmpty
         *      判断链表是否为空
         * @param N/A
         * @return
         *      返回true则链表不为空,false为空
         */
        bool isEmpty(){return 0==m_size?true:false;}
        /**
         * @brief clear
         *      清除链表中的数据
         * @param N/A
         * @return N/A
         */
        void clear();
        /**
         * @brief print
         *      打印链表中的信息,包括:
         *          原件名.起始点坐标,长宽信息
         * @param N/A
         * @return N/A
         */
        void print();

        // push & pull function
        /**
         * @brief pushBack
         *      从链表后面添加元素
         * @param measureObj
         *      添加的元素为measureObj类型
         * @return N/A
         */
        void pushBack(MeasuredObj& measureObj);
        /**
         * @brief pushFront
         *      从链表前面添加元素
         * @param measureObj
         *      添加的元素为measureObj类型
         * @return N/A
         */
        void pushFront(MeasuredObj& measureObj);
        /**
         * @brief pullBack
         *      从链表尾部删除元素
         * @param N/A
         * @return N/A
         */
        void pullBack();
        /**
         * @brief pullFront
         *      从链表头部删除元素
         * @param N/A
         * @return N/A
         */
        void pullFront();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_size {0};
        MeasuredObj* m_pHead {nullptr};
        MeasuredObj* m_pTail {nullptr};
    };
}//End of namespace Job

#endif // MEASUREDLIST_HPP

