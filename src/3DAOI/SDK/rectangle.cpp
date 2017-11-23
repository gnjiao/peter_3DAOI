#include "rectangle.hpp"


SDK::Rectangle::Rectangle()
{
    this->m_xPos = 0;
    this->m_yPos = 0;
    this->m_width = 0;
    this->m_height = 0;
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

SDK::Rectangle::~Rectangle()
{

}

