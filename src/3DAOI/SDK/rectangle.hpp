#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

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


    private:
        double m_xPos;
        double m_yPos;
        double m_angle;
        double m_width;
        double m_height;
    };

}//End of SDK



#endif // RECTANGLE_HPP
