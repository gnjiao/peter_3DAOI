#ifndef MEASUREOBJ_HPP
#define MEASUREOBJ_HPP

#include <iostream>

#include "../SDK/rectangle.hpp"

namespace Job
{
    /**
     *  @brief MeasureObj
     *
     *  @author peter
     *  @version 1.00 2017-11-22 peter
     *                note:create it
     */
    class MeasureObj
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor
        MeasureObj();
        MeasureObj( std::string name,
                    SDK::Rectangle& body );
        MeasureObj(const MeasureObj& measureObj);
        virtual~MeasureObj();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set function
        std::string name()const{return this->m_name;}
        SDK::Rectangle body()const{return this->m_body;}

        MeasureObj *pre()const{return this->m_pPre;}
        void setPre(MeasureObj* pPre){this->m_pPre = pPre;}
        MeasureObj *next()const{return this->m_pNext;}
        void setNext(MeasureObj* pNext){this->m_pNext = pNext;}
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;
        SDK::Rectangle m_body;
        MeasureObj* m_pPre {nullptr};
        MeasureObj* m_pNext {nullptr};
    };
}//End of namespace Job

#endif // MEASUREOBJ_HPP
