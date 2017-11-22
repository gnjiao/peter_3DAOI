#ifndef CAPTURESETTING_HPP
#define CAPTURESETTING_HPP

#include <iostream>

#include <QSettings>
#include <QFile>
#include <QMetaEnum>

#include "../SDK/customexception.hpp"

namespace App
{
    /**
     *  @brief CaptureSetting
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class CaptureSetting
    {
    public:
//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // constructor & destructor
        /**
         * @brief CaptureSetting
         *      构造函数
         * @param N/A
         * @return N/A
         */
        CaptureSetting();
        /**
         * @brief CaptureSetting
         *      构造函数
         * @param imageWidth
         *      标定的图像宽度
         * @param imageHeight
         *      标定的图像高度
         * @param imageBits
         *      图像的位数
         * @return N/A
         */
        CaptureSetting( int imageWidth,
                        int imageHeitht,
                        int imageBits );
        /**
         * @brief ~CaptureSetting
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual~CaptureSetting();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // load function
        /**
         *  @brief loadCaptureSetting
         *      加载配置文件
         *  @param path
         *      待加载的配置文件路径
         *  @return N/A
         */
        void loadCaptureSetting( const QString& path );
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_imageWidth;
        int m_imageHeight;
        int m_imageBits;

        /**
         *  @brief readCaptureSetting
         *      读取配置文件中的信息(配置文件存在)
         *  @param path
         *      待读取的配置文件路径
         *  @return N/A
         */
        void readCaptureSetting( const QString& path );
    };
}//End of App

#endif // CAPTURESETTING_HPP
