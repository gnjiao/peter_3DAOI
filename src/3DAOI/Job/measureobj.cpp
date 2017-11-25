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
    this->m_pPre = nullptr;
    this->m_pNext = nullptr;
}

Job::MeasureObj::MeasureObj(const MeasureObj &measureObj)
{
    this->m_name = measureObj.getName();

    this->m_body.setPosX( measureObj.getBody().getPosX() );
    this->m_body.setPosY( measureObj.getBody().getPosY() );
    this->m_body.setWidth( measureObj.getBody().getWidth() );
    this->m_body.setHeight( measureObj.getBody().getHeight() );

    this->m_pPre = measureObj.getPre();
    this->m_pNext = measureObj.getNext();
}

Job::MeasureObj::~MeasureObj()
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

