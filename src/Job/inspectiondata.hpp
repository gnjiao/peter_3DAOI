#ifndef INSPECTIONDATA_HPP
#define INSPECTIONDATA_HPP

#include <iostream>
#include <iomanip>
#include <string>

#include <QDomDocument>
#include <QTextStream>
#include <QFile>

#include "../DB/sqlitedb.hpp"
#include "../Job/board.hpp"

//std::string sqliteDataPath = "../data/";

namespace Job
{
    class InspectionData
    {
    public:
        InspectionData();

        virtual~InspectionData();

        Job::Board& board(){return this->m_board;}

        std::string version(){return this->m_version;}
        void setVersion(std::string version){this->m_version = version;}

        std::string editingTime(){return this->m_lastEditingTime;}
        void setEditingTime(std::string time){this->m_lastEditingTime = time; }

        void print();
        void writeToXml(const QString& path);
        void readFromDB(const std::string& path);
        void writeToDB(const std::string& path);

    private:
        Job::Board m_board;
        std::string m_version {"V1"};
        std::string m_lastEditingTime {"2000-01-01 00:00:00"};

    };
}//End of namespace Job


#endif // INSPECTIONDATA_HPP
