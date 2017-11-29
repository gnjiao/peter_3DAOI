#include "measurelist.hpp"

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor function
Job::MeasureList::MeasureList()
{

}

Job::MeasureList::~MeasureList()
{
    clear();
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//clear & print function

void Job::MeasureList::clear()
{
    if ( !isEmpty() )
    {
        this->m_pHead = nullptr;
        this->m_pTail = nullptr;
    }
}

void Job::MeasureList::print()
{
    const int cnt = size();
    //从链表头到链表尾
    if ( !isEmpty() )
    {
        MeasureObj* pTemp = this->m_pHead;
        for ( int i = 0;i < cnt; ++i )
        {
            std::cout << pTemp->name() << "\t"
                      << pTemp->body().xPos() << "\t"
                      << pTemp->body().yPos() << "\t"
                      << pTemp->body().width() << "\t"
                      << pTemp->body().height()
                      << std::endl;

            pTemp = pTemp->next();
        }
        delete pTemp;
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
void Job::MeasureList::pushBack( Job::MeasureObj& measureObj)
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
        m_pTail = &measureObj;
    }
    this->m_size++;
}

void Job::MeasureList::pushFront(MeasureObj &measureObj)
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
        m_pHead = &measureObj;
    }
    this->m_size++;
}

void Job::MeasureList::pullBack()
{
        if ( isEmpty() )
        {
            std::cout << ("the linked list is empty")
                      << std::endl;
        }
        else if ( 1 == size() )
        {
            this->m_pHead = nullptr;
            this->m_pTail = nullptr;
            m_size--;
        }
        else
        {
            m_pTail = m_pTail->pre();
            m_pTail->setNext(nullptr);
            m_size--;
        }
}

void Job::MeasureList::pullFront()
{
        if ( isEmpty() )
        {
            std::cout << ("the linked list is empty")
                      << std::endl;
        }
        else if ( 1 == size() )
        {
           this->m_pHead = nullptr;
           this->m_pTail = nullptr;
            m_size--;
        }
        else
        {
            m_pHead = m_pHead->next();
            m_pHead->setPre(nullptr);
            m_size--;
        }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------








