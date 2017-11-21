#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace SDK {

    class Rectangle
    {
    public:
        Rectangle();
        Rectangle(double xPos,
                  double yPos,
                  double width,
                  double height );
        ~Rectangle();

    private:
        double m_xPos;
        double m_yPos;
        double m_width;
        double m_height;
    };

}



#endif // RECTANGLE_HPP
