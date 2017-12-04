#include "measuredlist.hpp"

using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor function
MeasuredList::MeasuredList()
{

}

MeasuredList::~MeasuredList()
{
    clear();
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//clear & print function
void MeasuredList::clear()
{
    if ( !isEmpty() )
    {
        this->m_size = 0;
        this->m_pHead = nullptr;
        this->m_pTail = nullptr;
    }
}
void MeasuredList::print()
{
    const int cnt = size();
    //从链表头到链表尾
    if ( !isEmpty() )
    {
        std::cout << std::setw(10) << std::left << "Name"
                  << std::setw(10) << std::left << "x"
                  << std::setw(10) << std::left << "y"
                  << std::setw(10) << std::left << "width"
                  << std::setw(10) << std::left << "height"
                  << std::endl;

        MeasuredObj* pTemp = this->m_pHead;
        for ( int i = 0;i < cnt; ++i )
        {
            std::cout << std::setw(10) << std::left<< pTemp->name()
                      << std::setw(10) << std::left<< pTemp->body().xPos()
                      << std::setw(10) << std::left<< pTemp->body().yPos()
                      << std::setw(10) << std::left<< pTemp->body().width()
                      << std::setw(10) << std::left<< pTemp->body().height()
                      << std::endl;
            pTemp = pTemp->pNext();
        }
        pTemp = nullptr;
    }
    else
    {
        std::cout << "the linked list is empty" << std::endl;
    }
    //链表为空
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//push & pull function
void MeasuredList::pushBack( MeasuredObj& measureObj)
{
    if(isEmpty())
    {
        this->m_pHead = &measureObj;
        this->m_pTail = &measureObj;
    }
    else
    {
        this->m_pTail->setNext(&measureObj);
        measureObj.setPre(this->m_pTail);
        measureObj.setNext(nullptr);
        m_pTail = &measureObj;
    }
    this->m_size++;
}

void MeasuredList::pushFront(MeasuredObj& measureObj)
{
    if(isEmpty())
    {
        this->m_pHead = &measureObj;
        this->m_pTail = &measureObj;
    }
    else
    {
        this->m_pHead->setPre(&measureObj);
        measureObj.setNext(this->m_pHead);
        measureObj.setPre(nullptr);
        m_pHead = &measureObj;
    }
    this->m_size++;
}

void MeasuredList::pullBack()
{
    if ( isEmpty() )
    {
        std::cout << "the linked list is empty\n";
    }
    else if ( 1 == size() )
    {
        this->m_pHead = nullptr;
        this->m_pTail = nullptr;
        m_size--;
    }
    else
    {
        m_pTail = m_pTail->pPre();
        m_pTail->setNext(nullptr);
        m_size--;
    }
}

void MeasuredList::pullFront()
{
    if ( isEmpty() )
    {
        std::cout << "the linked list is empty\n";
    }
    else if ( 1 == size() )
    {
        this->m_pHead = nullptr;
        this->m_pTail = nullptr;
        m_size--;
    }
    else
    {
        m_pHead = m_pHead->pNext();
        m_pHead->setPre(nullptr);
        m_size--;
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------








