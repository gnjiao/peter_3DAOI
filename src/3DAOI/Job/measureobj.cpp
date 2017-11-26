#include "measureobj.hpp"

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor
Job::MeasureObj::MeasureObj()
{

}

Job::MeasureObj::MeasureObj(std::string name,
                            SDK::Rectangle &body)
{
    this->m_name = name;
    this->m_body = body;
}

Job::MeasureObj::MeasureObj(const MeasureObj &measureObj)
{
    this->m_name = measureObj.getName();
    this->m_body = measureObj.getBody();
//    this->m_pPre = measureObj.getPre();
//    this->m_pNext = measureObj.getNext();
}

Job::MeasureObj::~MeasureObj()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

