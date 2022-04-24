
#include <memory>
class HttpServer;
class HttpData
{
private:
    std::weak_ptr<HttpServer> m_server;
    int m_fd;
public:
    HttpData(int fd,std::shared_ptr<HttpServer> server)
    {
        m_fd = fd;
        m_server = server;
    }
    ~HttpData()
    {}

    void Close()
    {
        std::shared_ptr<HttpServer> server = m_server.lock();
        if(server)
        {
            server->Erase(m_fd);
        }
    }
};

class HttpServer
{
private:
    std::map<int,std::shared_ptr<HttpData>> m_mapHttpData;

public:
    HttpServer()
    {

    }
    ~HttpServer()
    {

    }
    void Erase(int fd)
    {
        m_mapHttpData.erase(fd);
    }
};



int main()
{
    std::shared_ptr<HttpServer> spServer(new Server);

}