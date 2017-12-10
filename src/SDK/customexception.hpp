#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>
#include <iostream>

namespace SDK
{
// 异常时,将文件名、行号、函数名和详细信息+上一层的异常一起抛出
#define THROW_EXCEPTION(exMsg)\
{\
     std::ostringstream message;\
     message <<"File: "<<__FILE__<<"\n"\
             <<"Line:"<<__LINE__<<"\n"\
             <<"Func:"<<__FUNCTION__<<"\n"\
             <<"Detail:"<< exMsg <<"\n";\
     std::string msg = message.str();\
     throw  SDK::CustomException(msg);\
}

#define CATCH_AND_RETHROW_EXCEPTION(appendedMsg)\
catch ( SDK::CustomException& ex )\
{\
    std::ostringstream message;\
    message <<"File: "<<__FILE__<<"\n"\
            <<"Line:"<<__LINE__<<"\n"\
            <<"Func:"<<__FUNCTION__<<"\n"\
            <<"Detail:"<< appendedMsg <<"\n"\
            <<ex.what()<<"\n";\
    std::string msg = message.str();\
    throw  SDK::CustomException(msg);\
}

#define PRINT_EXCEPTION()\
catch( SDK::CustomException& ex )\
{\
    std::cout << ex.what() << std::endl;\
}

/**
 *  @brief CustomException
 *
 *      CustomException类是自定义异常类.
 *
 *  @author peter
 *  @version 1.00 2017-11-21 peter
 *                note:create it
 */
    class CustomException : public std::exception
    {

    public:
        //>>>-------------------------------------------------------------------
        // constructor & destructor
        /**
         * @brief CustomException
         *      默认构造函数
         * @param N/A
         * @return N/A
         */
        CustomException();
        /**
         * @brief CustomException
         *      构造函数
         * @param message
         *      需要显示的异常信息
         * @return N/A
         */
        CustomException(std::string& message);
        /**
         * @brief ~CustomException
         *      析构函数
         * @param N/A
         * @return N/A
         */
        virtual ~CustomException();


        //>>>-------------------------------------------------------------------
        const std::string originalMsg ( )const{return this->m_originalMsg;}
        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT override{return m_originalMsg.data();}


    private:
        std::string m_originalMsg;
    };

}//End of namespace SDK

#endif // CUSTOMEXCEPTION_HPP
