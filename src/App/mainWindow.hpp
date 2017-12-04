#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QString>

#include "appsetting.hpp"
#include "capturesetting.hpp"

#include "../SDK/randomdigit.hpp"
#include "../Job/inspectiondata.hpp"

namespace App
{
    /**
     *  @brief MainWindow
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class MainWindow
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor function
        /**
         * @brief MainWindow
         *      构造函数
         * @param N/A
         * @return N/A
         */
        MainWindow();
        /**
         * @brief ~MainWindow
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual~MainWindow();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //load & scan function
        /**
         * @brief loadSetting
         *      加载配置文件:
         *          1.appSetting的配置文件
         *          2.captureSetting的配置文件
         * @param appSettingPath
         *      appSetting配置文件的路径
         * @param captureSettingPath
         *      captureSetting配置文件的路径
         * @return N/A
         */
        void loadSetting( const QString& appSettingPath,
                          const QString& captureSettingPath );
        /**
         * @brief scanJobFolder
         *      扫描程式文件目录下是否有程式文件
         *          1.没有程式文件则自动创建,写入默认值
         *          2.有程式文件则加载程式文件,读取数据信息
         * @param path
         *      待扫描的存放程式文件的文件夹路径
         * @return N/A
         */
        void scanJobFolder(const QString& path);
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    private:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //generate data
        /**
         * @brief generateObjsRandomly
         *      生成随机数据,包括:
         *          1.默认的版本号.最后的编辑时间
         *          2.默认的job程式名.原点位置.尺寸大小
         *          3.随机的原件信息(原件名.起点位置.长宽尺寸)
         * @param chipCnt
         *          需要生成数据的chip原件数量
         * @param icCnt
         *          需要生成数据的ic原件数量
         * @return N/A
         */
        void generateObjsRandomly(int chipCnt,int icCnt);
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        App::AppSetting m_appSetting;
        App::CaptureSetting m_captureSetting;

        Job::InspectionData m_inspectionData;
    };
}//End of namespace App


#endif // APPLICATION_HPP
