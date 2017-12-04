#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#include <QDomDocument>
#include <QTextStream>
#include <QFile>

#include "measuredlist.hpp"

namespace Job
{
    class Board
    {
    public:
        Board();
        virtual~Board();

        Job::MeasuredList& measuredList(){return this->m_measureList;}

        std::string& name(){return this->m_name;}
        void setName(std::string name){this->m_name = name;}

        double& originalX(){return this->m_originalX;}
        void setOriginalX(double originalX){this->m_originalX = originalX;}

        double& originalY(){return this->m_originalY;}
        void setOriginalY(double originalY){this->m_originalY = originalY;}

        double& sizeX(){return this->m_sizeX;}
        void setSizeX(double sizeX){this->m_sizeX = sizeX;}

        double& sizeY(){return this->m_sizeY;}
        void setSizeY(double sizeY){this->m_sizeY = sizeY;}


        void writeToXml(QDomDocument doc,QDomElement job);
        void print();


    private:
        Job::MeasuredList m_measureList;
        std::string m_name {"iPhoneV1"};
        double m_originalX {0};
        double m_originalY {0};
        double m_sizeX {200};
        double m_sizeY {200};

    };
}//End of namespace Job


#endif // BOARD_HPP
