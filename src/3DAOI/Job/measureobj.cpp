#include "measureobj.hpp"


Job::MeasureObj::MeasureObj()
{

}

Job::MeasureObj::MeasureObj(std::string name,
                            SDK::Rectangle &body,
                            Job::MeasureObj *pPre,
                            Job::MeasureObj *pNext)
{
    this->m_name = name;
    this->m_body = body;
    this->m_pPre = pPre;
    this->m_pNext = pNext;
}

Job::MeasureObj::~MeasureObj()
{

}

Job::MeasureObj *Job::MeasureObj::getPre()
{
    return this->m_pPre;
}

Job::MeasureObj *Job::MeasureObj::getNext()
{
    return this->m_pNext;
}

void Job::MeasureObj::setPre(Job::MeasureObj *pPre)
{
    this->m_pPre = pPre;
}

void Job::MeasureObj::setNext(Job::MeasureObj *pNext)
{
    this->m_pNext = pNext;
}
