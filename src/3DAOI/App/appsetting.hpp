#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>

#include <QSettings>
#include <QFile>
#include <QMetaEnum>

#include "../SDK/customexception.hpp"

#define VAR_TO_STR(var)\
    ({\
        std::string name = (#var);\
        int pos = 0;\
        int length = 0;\
        length = name.length();\
        pos = name.find_last_of(':',length);\
        if ( pos == -1 )\
        {\
            pos = 0;\
            name = name.substr(pos,length);\
        }\
        else\
        {\
            name = name.substr(length - pos,length);\
        }\
        (name);\
    })

enum MachineName {AOI,SPI};
enum Theme {BLACK,WHITE};
enum Language {EN,CN};
enum LaneMode {SIMULATOR,SINGLELANE,DUALLANE};

namespace App
{
    /**
     *  @brief AppSetting
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class AppSetting
    {
    public:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // constructor & destructor
        /**
         * @brief AppSetting
         *      构造函数
         * @param N/A
         * @return N/A
         */
        AppSetting();
        /**
         * @brief ~CaptureSetting
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual ~AppSetting();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // load function
        /**
         *  @brief loadAppSetting
         *      加载配置文件
         *  @param path
         *      待加载的配置文件路径
         *  @return N/A
         */
        void loadAppSetting(const QString& path);
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //read & write function
        /**
         *  @brief readCaptureSetting
         *      读取配置文件中的信息(配置文件存在)
         *  @param path
         *      待读取的配置文件路径
         *  @return N/A
         */
        void readAppSetting( const QString& path );
        /**
         *  @brief readCaptureSetting
         *      写入配置信息到文件中(配置文件不存在)
         *  @param path
         *      待写入的配置文件路径
         *  @return N/A
         */
        void writeAppSetting( const QString& path );
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_companyName {"SciJet"};
        MachineName m_machineName {AOI};
        Theme m_theme {WHITE};
        Language m_lang {EN};
        LaneMode m_laneMode {DUALLANE};
    };

}//End of App

#endif //APPSETTING_HPP













