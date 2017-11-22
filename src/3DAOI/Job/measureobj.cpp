#include "measureobj.hpp"


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
