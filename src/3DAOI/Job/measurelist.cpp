#include "measurelist.hpp"

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor function
Job::MeasureList::MeasureList()
{
    this->m_size = 0;
    this->m_pHead = nullptr;
    this->m_pTail = nullptr;
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
    //从链表头到链表尾的方式逐个删除
    if ( !isEmpty() )
    {
        for ( int i = 0;i < size(); ++i )
        {
            this->m_pHead = this->m_pHead->getNext();
            delete this->m_pHead->getPre();
            this->m_pHead->setPre(nullptr);
            m_size--;
        }
    }
    //如果链表本来就为空，就没必要再进for循环了
}

void Job::MeasureList::print()
{
    //从链表头到链表尾
    const int cnt = size();
    if ( !isEmpty() )
    {
        MeasureObj* pTemp = this->m_pHead;
        for ( int i = 1;i <= cnt; ++i )
        {
            std::cout << pTemp->getName() << "\t"
                      << pTemp->getBody().getPosX() << "\t"
                      << pTemp->getBody().getPosY() << "\t"
                      << pTemp->getBody().getWidth() << "\t"
                      << pTemp->getBody().getHeight()
                      << std::endl;

            pTemp = pTemp->getNext();
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

void Job::MeasureList::pullBack()
{
    try
    {
        if ( isEmpty() )
        {
            THROW_EXCEPTION("the linked list is empty");
        }
        else
        {
            this->m_pTail = this->m_pTail->getPre();
            delete this->m_pTail->getNext();
            this->m_pTail->setNext(nullptr);
            m_size--;
        }
    }
    catch ( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what())
    }
}

void Job::MeasureList::pullFront()
{
    try
    {
        if ( isEmpty() )
        {
            THROW_EXCEPTION("the linked list is empty");
        }
        else
        {
            this->m_pHead = this->m_pHead->getNext();
            delete this->m_pHead->getPre();
            this->m_pHead->setPre(nullptr);
            m_size--;
        }
    }
    catch ( const SDK::CustomException& ex )
    {
        THROW_EXCEPTION(ex.what())
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------








