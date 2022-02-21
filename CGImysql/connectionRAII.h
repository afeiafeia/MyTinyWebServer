#ifndef MY_TINY_WEB_CONNECTION_RAII_H
#define MY_TINY_WEB_CONNECTION_RAII_H

#include "sql_connection_pool.h"
#include "mysql/mysql.h"
class connectionRAII
{
private:
    connection_pool* m_ConnPool;
    MYSQL*          m_MYSQL;

public:
    connectionRAII(){}
    connectionRAII(MYSQL **con, connection_pool *connPool);
    ~connectionRAII();

};
#endif