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
    this->m_xPos = rectangle.getPosX();
    this->m_yPos = rectangle.getPosY();
    this->m_angle = rectangle.getAngle();
    this->m_width = rectangle.getWidth();
    this->m_height = rectangle.getHeight();
}

SDK::Rectangle::~Rectangle()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


