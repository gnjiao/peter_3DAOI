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
                    SDK::Rectangle& body,
                    MeasureObj* pPre=nullptr,
                    MeasureObj* pNext=nullptr );
        virtual~MeasureObj();
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set function
        MeasureObj* getPre();
        MeasureObj* getNext();
        void setPre(MeasureObj* pPre);
        void setNext(MeasureObj* pNext);
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;
        SDK::Rectangle m_body;
        MeasureObj* m_pPre;
        MeasureObj* m_pNext;
    };
}

#endif // MEASUREOBJ_HPP
