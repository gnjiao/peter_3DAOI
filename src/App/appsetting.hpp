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
    //>>>------------------------------------------------------------------------------------
    //enum
    /**
     * @brief The MachineName enum
     *      机器名称
     */
    enum class MachineName
    {
        AOI,    // 自动光学检测设备
        SPI     // 锡膏检测设备
    };
    /**
     * @brief The Theme enum
     *      界面主题
     */
    enum class Theme
    {
        BLACK,
        WHITE
    };
    /**
     * @brief The Language enum
     *      机器语言
     */
    enum class Language
    {
        EN,
        CN
    };
    /**
     * @brief The LaneMode enum
     *      机器种类
     */
    enum class LaneMode
    {
        SIMULATOR,      // 模拟器,模拟机器运行的电脑
        SINGLE_LANE,    // 单轨机,只有一条轨道的机器
        DUAL_LANE       // 双轨机,有两条轨道的机器
    };


    /**
     *  @brief AppSetting
     *
     *          AppSetting类是检查配置文件的类,所检查的配置文件包括主题、语言等
     *      不是程序运行时所必需的配置;如果不存在则直接创建默认的配置,存在则配
     *      置是否正确,不正确则使用默认参数.
     *
     *      使用操作:
     *          将配置文件路径传入loadAppSetting()函数,读取配置文件中的配置:
     *              a.配置文件不存在则自动生成默认配置文件
     *              b.配置文件存在但参数不正确则自动改为默认配置
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class AppSetting
    {
    public:
        //>>>--------------------------------------------------------------------------------
        // constructor & destructor
        /**
         * @brief AppSetting
         *      默认构造函数
         */
        AppSetting();
        /**
         * @brief ~CaptureSetting
         *      析构函数
         */
        virtual ~AppSetting();

        //>>>--------------------------------------------------------------------------------
        // load function
        /**
         *  @brief loadAppSetting
         *      加载UI界面的配置文件
         *  @param path
         *      待加载的配置文件路径
         *  @return N/A
         */
        void loadAppSetting(const QString& appSettingPath);

    private:
        //>>>--------------------------------------------------------------------------------
        // read & write function
        /**
         *  @brief readAppSetting
         *      配置文件存在时,读取配置文件中的信息
         *  @param path
         *      待读取的配置文件路径
         *  @return N/A
         */
        void readAppSetting(const QString& appSettingPath );
        /**
         *  @brief writeAppSetting
         *      配置文件不存在时,将默认配置信息写到文件中
         *  @param path
         *      待写入的配置文件路径
         *  @return N/A
         */
        void writeAppSetting(const QString& appSettingPath );

    private:
        // 公司名称，默认为“SciJet”
        std::string m_companyName {"SciJet"};
        // 设备类型，AOI为检测贴片元件设备，SPI为检测锡膏设备
        MachineName m_machineName {MachineName::AOI};
        // 软件内运行时的主题
        Theme m_theme {Theme::WHITE};
        // 软件内运行时的语言
        Language m_lang {Language::EN};
        // 机器设备的种类，分为模拟器，单条轨道的机器和两条轨道的机器
        LaneMode m_laneMode {LaneMode::DUAL_LANE};
    };

}//End of namespace App

#endif //APPSETTING_HPP













