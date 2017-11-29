#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#include "measurelist.hpp"

namespace Job
{
    class Board
    {
    public:
        Board();
        virtual~Board();

        void writeToXml(std::string name);


    private:
        Job::MeasureList m_measureList;
        std::string m_name;
        double m_sizeX;
        double m_sizeY;
        double m_originalX;
        double m_originalY;
    };
}//End of namespace Job


#endif // BOARD_HPP
