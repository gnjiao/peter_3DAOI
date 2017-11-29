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
    this->m_name = measureObj.name();
    this->m_body = measureObj.body();
}

Job::MeasureObj::~MeasureObj()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

