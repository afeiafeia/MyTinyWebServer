#ifndef MY_TINY_WEB_HTTP_H
#define MY_TINY_WEB_HTTP_H

#include <netinet/in.h>
#include <bits/socket.h>
#include <string>
#include <sys/stat.h>
#include <bits/types/struct_iovec.h>
#include "../CGImysql/sql_connection_pool.h"
#include <map>
#define READ_BUFF_SIZE  2048
#define WRITE_BUFF_SIZE 2048
class http_conn
{
public:
    enum Method
    {
        GET=0,
        POST,
        HEAD,
        PUT,
        DELETE,
        TRACE,
        OPTIONS,
        CONNECT,
        PATH
    };

    enum CHECK_STATE
    {
        CHECK_STATE_REQUESTLINE=0,
        CHECK_STATE_HEADER,
        CHECK_STATE_CONTNET
    };
    enum LINE_STATE
    {
        LINE_OK=0,
        LINE_BAD,
        LINE_OPEN
    };

    enum HTTP_STATE
    {
        NO_REQUEST=0,//请求不完整，需要继续读取请求数据(跳转到主线程继续监测读事件)
        GET_REQUEST, //获得了完整的http请求
        BAD_REQUEST, //请求报文有语法错误
        FORBIDDEN_REQUEST, //服务器内部错误，该结果在主状态机逻辑switch的default下，一般不会触发
        INTERNAL_ERROR,
        CLOSED_CONNECTION,
        FILE_REQUEST
    };

    http_conn(){}
    ~http_conn(){};

public:
    void init(int sockfd,sockaddr_in &iAddr,char* root,int TRIGMode,int close_log,string user,string passwd,string sqlname);
    void init();

    void initmysql_result(connection_pool *connPool);

    void addfd(int epollfd,bool one_shot);
    int SetNoBlock();

    bool read_once();

    //解析一行
    //确定当前行是否完整，如果完整，将末尾的\r\n替换为\0\0;并更新m_check_idx为下一行的第一个字符的在报文中的下标
    LINE_STATE parse_line();

    void process();

    bool write();

    sockaddr_in* getaddress(){return &m_addr;}
private:
    HTTP_STATE process_read();

    //解析请求头
    HTTP_STATE parse_request_line(char* ipCurLine);
    
    //解析首部行
    HTTP_STATE parse_headers(char* ipCurLine);
    char* GetCurLine();

    //解析实体体
    HTTP_STATE parse_content(char* ipCurLine);

    //修改监测读事件
    void modfd(int event);

    //会根据解析出来的请求，打开相应的文件并映射到虚拟地址空间
    HTTP_STATE do_request();

    //这一步并不是发送报文，而是将报文存储信息iovec中，
    //之后，process中会注册监测套接字的可写事件，
    //可写时，工作线程调用write进行响应，将报文发送给浏览器
    bool process_write(HTTP_STATE ret);

    bool add_response(const char* format,...);

    //添加状态行
    bool add_status_line(int status,const char* title);
    //添加消息报头
    bool add_header(int connext_status);
    //向首部行添加conteng_len字段，表示响应报文实体体的长度
    bool add_content_length(int content_len);
    //添加文本类型content_Type字段
    bool add_content_type();
    //添加连接状态connection字段：close(短连接)或者keep-alive（长连接）
    bool add_connection();
    //添加空行
    bool add_blank_line();
    //添加实体体
    bool add_content(const char* content);


public:
    static int m_epollfd;
    static int m_connfd_num;//连接描述符的数量
    int        m_improv;   //如果写事件正确处理，该值被置为1，而time_flag为0，如果处理失败，两个值都为1
    int        m_time_flag;
    int m_state;          //套接字的读写状态：读为0, 写为1
    MYSQL *mysql;
private:
    int m_sockfd;         //连接对应的TCP套接字
    sockaddr_in m_addr;   //套接字的目的地址（客户端地址）
    int m_TRIGMode;       //epoll中监测套接字时的触发方式：1-ET，0-LT

    char m_read_buff[READ_BUFF_SIZE]; //读缓冲区（套接字可读时，将数据读到此缓冲区）
    int m_read_index; //读取到的字节数，而不是最后一个字节的下标

    char m_write_buff[WRITE_BUFF_SIZE];
    int m_write_index;
    //这里的读缓冲区存在一个问题：缓冲区大小是固定的，而且比较小，如果一个报文比较大，缓冲区放不下，读取的报文就不完整
    //muduo中使用了临时栈上空间，使用readv读取，详看muduo7.4.7节

    //写的时候使用了struct iovec，不存在此问题
    int m_start_line;//每次解析一行之后，m_start_line指向该行的第一个字符在m_read_buff中的下标，而m_check_idx指向下一行待解析的行首下标
    int m_check_idx;

    //请求行
    char* m_url;//URL
    int m_cgi;  //对应post请求，post请求下，值为1（表示true），其他情况下为0（表示false）
    Method      m_method;//方法
    char* m_version;//版本

    //首部行
    linger m_LingerOpt;
    bool m_linger;//长、短连接，true表示长连接
    int  m_ContentLength; //实体体长度

    char* m_browser;//浏览器版本

    char* m_host;//主机域名
    char* m_file_address;
    //实体体
    std::string m_content;//用户名+密码

    CHECK_STATE m_check_state;



    //
    char* m_root;//根目录
    char  m_real_file_path[256];  //所请求文件所在的路径
    struct stat m_file_stat;//文件的属性信息
    struct iovec m_io[2];
    int m_io_count;
    int byte_to_send;
    int byte_have_send;


    map<string,string> m_user;

    int m_close_log;

    //SQL
    char sql_user[100];
    char sql_passwd[100];
    char sql_name[100];



};

#endif