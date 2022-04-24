#include "Singleton2.h"

mySingleTon* mySingleTon::m_pSingleTon = new mySingleTon();

mySingleTon::mySingleTon()
{

}

mySingleTon* mySingleTon::GetInstance()
{
    return m_pSingleTon;
}

