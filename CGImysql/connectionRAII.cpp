#include "connectionRAII.h"
#include <exception>

//connectionRAII::connectionRAII(connection_pool* ipConnPool)
//{
//    if(ipConnPool==nullptr)
//    {
//        throw std::exception();;
//    }
//    m_MYSQL = ipConn->GetConnection();
//    m_ConnPool = ipConnPool;
//}
connectionRAII::connectionRAII(MYSQL **con, connection_pool *ipConnPool)
{
    if(ipConnPool==nullptr)
    {
        throw std::exception();
    }
    *con = ipConnPool->GetConnection();
    m_MYSQL = *con;
    m_ConnPool = ipConnPool;
}
connectionRAII::~connectionRAII()
{
    m_ConnPool->ReleaseConnection(m_MYSQL);
}


