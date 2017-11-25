#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

namespace SDK
{
/**
 *  @brief Rectangle
 *
 *  @author peter
 *  @version 1.00 2017-11-21 peter
 *                note:create it
 */
    class Rectangle
    {
    public:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor
        /**
         * @brief Rectangle
         *      构造函数
         * @param N/A
         * @return N/A
         */
        Rectangle();
        /**
         * @brief Rectangle
         *      构造函数
         * @param xPos
         *      图像x轴坐标
         * @param yPos
         *      图像y轴坐标
         * @param width
         *      图像宽度
         * @param height
         *      图像高度
         * @return N/A
         */
        Rectangle( double xPos,
                   double yPos,
                   double width,
                   double height );
        /**
         * @brief Rectangle
         *      构造函数
         * @param xPos
         *      图像x轴坐标
         * @param yPos
         *      图像y轴坐标
         * @param angle
         *      图像旋转角度
         * @param width
         *      图像宽度
         * @param height
         *      图像高度
         * @return N/A
         */
        Rectangle( double xPos,
                   double yPos,
                   double angle,
                   double width,
                   double height );
        /**
         * @brief ~Rectangle
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual ~Rectangle();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // get & set function
        double getPosX()const {return this->m_xPos;}
        double getPosY()const {return m_yPos;}
        double getAngle()const {return m_angle;}
        double getWidth()const {return m_width;}
        double getHeight()const {return m_height;}

        void setPosX(double xPos){ this->m_xPos = xPos;}
        void setPosY(double yPos){ this->m_yPos = yPos;}
        void setAngle(double angle){ this->m_angle = angle;}
        void setWidth(double width){ this->m_width = width;}
        void setHeight(double height){ this->m_height = height;}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        double m_xPos;
        double m_yPos;
        double m_angle;
        double m_width;
        double m_height;
    };

}//End of SDK

#endif // RECTANGLE_HPP
