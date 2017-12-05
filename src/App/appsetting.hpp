#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>

#include <QSettings>
#include <QFile>
#include <QMetaEnum>

#include "../SDK/customexception.hpp"
#include "../SDK/formatconversion.hpp"

namespace App
{
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //enum
    enum class MachineName//机器名称,包括AOI和SPI两种
    {
        AOI,
        SPI
    };
    enum class Theme//界面主题,包括黑色和白色两个主题
    {
        BLACK,
        WHITE
    };
    enum class Language//语言种类,包括英文和中文两种语言
    {
        EN,
        CN
    };
    enum class LaneMode//机器种类,包括模拟器、单轨机和双轨机
    {
        SIMULATOR,
        SINGLE_LANE,
        DUAL_LANE
    };
    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
        MachineName m_machineName {MachineName::AOI};
        Theme m_theme {Theme::WHITE};
        Language m_lang {Language::EN};
        LaneMode m_laneMode {LaneMode::DUAL_LANE};
    };

}//End of namespace App

#endif //APPSETTING_HPP













