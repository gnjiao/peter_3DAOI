#include "rectangle.hpp"


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//constructor & destructor

SDK::Rectangle::Rectangle()
{

}

SDK::Rectangle::Rectangle( double xPos,
                           double yPos,
                           double width,
                           double height )
{
    this->m_xPos = xPos;
    this->m_yPos = yPos;
    this->m_width = width;
    this->m_height = height;
}

SDK::Rectangle::Rectangle( double xPos,
                           double yPos,
                           double angle,
                           double width,
                           double height )
{
    this->m_xPos = xPos;
    this->m_yPos = yPos;
    this->m_angle = angle;
    this->m_width = width;
    this->m_height = height;
}

SDK::Rectangle::Rectangle(const SDK::Rectangle &rectangle)
{
    this->m_xPos = rectangle.xPos();
    this->m_yPos = rectangle.yPos();
    this->m_angle = rectangle.angle();
    this->m_width = rectangle.width();
    this->m_height = rectangle.height();
}

SDK::Rectangle::~Rectangle()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


