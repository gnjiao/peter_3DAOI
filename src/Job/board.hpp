#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#include <QDomDocument>
#include <QTextStream>
#include <QFile>

#include "measuredlist.hpp"

namespace Job
{
    /**
     *  @brief Board
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class Board
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor function
        /**
         * @brief Board
         *      构造函数
         * @param N/A
         * @return N/A
         */
        Board();
        /**
         * @brief ~Board
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual~Board();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set function
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
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //write & print
        /**
         * @brief writeToXml
         *      将内存中检测程式的Board和MeasureObjs信息写入xml文件中
         *          1.Board名字,起始点位置,长宽尺寸
         *          2.MeasureObjs中各原件的位置信息和长宽信息
         * @param doc
         *      已创建的QDomDocument的信息
         * @param job
         *      已写入的QDomElement的信息
         * @return N/A
         */
        void writeToXml(QDomDocument doc,QDomElement job);
        /**
         * @brief print
         *      打印检测程式文件中Board信息
         * @param N/A
         * @return N/A
         */
        void print();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


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
