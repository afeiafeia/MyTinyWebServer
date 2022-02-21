#include "../log/log.h"


int main()
{
    int m_close_log = 0;
    log::GetInstance()->Init("./ServerLog", 0, 2000, 800000, 0);
    LOG_DEBUG("%s","This Is LOG Test!");
    return 0;
}