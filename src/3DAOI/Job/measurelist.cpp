#include "measurelist.hpp"


int Job::MeasureList::size()
{
    return m_size;
}

bool Job::MeasureList::isEmpty()
{
    return m_size == 0?true:false;
}

void Job::MeasureList::clear()
{
    //从链表头到链表尾的方式逐个删除
    const int cnt=size();
    if ( !isEmpty() )
    {
        MeasureObj* temp = nullptr;
        for (int i=1;i<=cnt;++i)
        {
            temp = m_pHead->getNext();
            delete m_pHead;
            m_pHead=temp;
            m_size--;
        }
    }
    //如果链表本来就为空，就没必要再进for循环了
}

void Job::MeasureList::pushBack(Job::MeasureObj measureObj)
{
    Job::MeasureObj* pMeasureObj = new Job::MeasureObj(measureObj);
    if(isEmpty())
    {
        m_pHead = pMeasureObj;
        m_pTail = pMeasureObj;
    }
    else
    {
        m_pTail->setNext(pMeasureObj);
        pMeasureObj->setPre(this->m_pTail);
        m_pTail = pMeasureObj;
    }
    this->m_size++;
}

void Job::MeasureList::pushFront(Job::MeasureObj measureObj)
{
    Job::MeasureObj* pMeasureObj = new Job::MeasureObj(measureObj);
    if(isEmpty())
    {
        this->m_pHead = pMeasureObj;
        this->m_pTail = pMeasureObj;
    }
    else
    {
        m_pHead->setPre(pMeasureObj);
        pMeasureObj->setNext(this->m_pHead);
        m_pHead = pMeasureObj;
    }
    this->m_size++;
}

//bool Job::MeasureList::pullBack()
//{
//    MeasureObj* pMeasureObj = NULL;
//    if ( isEmpty() )
//    {
//        std::cout << "the linked list is empty" << std::endl;
//        return false;
//    }
//    else
//    {
//        pMeasureObj = m_pTail;
//        m_pTail = pMeasureObj->getPre();
//    }
//}


