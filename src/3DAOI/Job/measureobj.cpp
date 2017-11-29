#include "measureobj.hpp"

using Job::MeasureObj;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor
MeasureObj::MeasureObj()
{

}

MeasureObj::MeasureObj(std::string name,
                            SDK::Rectangle &body)
{
    this->m_name = name;
    this->m_body = body;
}

MeasureObj::MeasureObj(const MeasureObj &measureObj)
{
    this->m_name = measureObj.name();
    this->m_body = measureObj.body();
}

MeasureObj::~MeasureObj()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

