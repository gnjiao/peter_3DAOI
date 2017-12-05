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

namespace Job
{
    /**
     *  @brief InspectionData
     *
     *  @author peter
     *  @version 1.00 2017-11-24 peter
     *                note:create it
     */
    class InspectionData
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor function
        /**
         * @brief InspectionData
         *      构造函数
         * @param N/A
         * @return N/A
         */
        InspectionData();
        /**
         * @brief ~InspectionData
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual~InspectionData();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set function
        Job::Board& board(){return this->m_board;}

        std::string version(){return this->m_version;}
        void setVersion(std::string version){this->m_version = version;}

        std::string editingTime(){return this->m_lastEditingTime;}
        void setEditingTime(std::string time){this->m_lastEditingTime = time; }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //write & read & print function
        /**
         * @brief writeToXml
         *
         * @param path
         */
        void writeToXml(const QString& path);
        /**
         * @brief print
         *      打印检测程式文件的版本和最后编辑时间的信息
         * @param N/A
         * @return N/A
         */
        void print();
        /**
         * @brief readFromDB
         *      读取数据库文件
         * @param path
         *      待读取的数据库文件路径
         * @return N/A
         */
        void readFromDB(const std::string& path);
        /**
         * @brief writeToDB
         *      将数据写入数据库文件并导出
         * @param path
         *      导出的数据库文件的路径
         * @return N/A
         */
        void writeToDB(const std::string& path);
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //read & convert function
        void readCurrentVersionDB(SSDK::DB::SqliteDB& sqlite);
        void convertFromV1(SSDK::DB::SqliteDB& sqlite);
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



    private:
        Job::Board m_board;
        std::string m_version {"V1"};
        std::string m_lastEditingTime {"2000-01-01 00:00:00"};

    };
}//End of namespace Job


#endif // INSPECTIONDATA_HPP
