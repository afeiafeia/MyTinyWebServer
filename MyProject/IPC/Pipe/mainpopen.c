#include "unpipc.h"
 int main(int argc,char** argv)
 {
     size_t n;
     char buff[MAXLINE];
     char command[MAXLINE];

     FILE* pfile = NULL;

     fgets(buff,MAXLINE,stdin);

     n = strlen(buff);
     if (buff[n-1]=='\n')
     {
        n--; /* code */
     }
     snprintf(command,sizeof(command),"cat %s",buff);
     pfile = popen(command,"r");
     while(fgets(buff,MAXLINE,pfile)!=NULL)
     fputs(buff,stdout);
     pclose(pfile);

     exit(0);


 }			 //销毁所有连接

	//单例模式
	static connection_pool *GetInstance();

	void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log); 

private:
	connection_pool();
	~connection_pool();

	int m_MaxConn;  //最大连接数
	int m_CurConn;  //当前已使用的连接数
	int m_FreeConn; //当前空闲的连接数
	locker lock;
	list<MYSQL *> connList; //连接池
	sem reserve;

public:
	string m_url;			 //主机地址
	int m_Port;		        //数据库端口号
	string m_User;		 //登陆数据库用户名
	string m_PassWord;	 //登陆数据库密码
	string m_DatabaseName; //使用数据库名
	int m_close_log;	//日志开关
};

class connectionRAII{

public:
	connectionRAII(MYSQL **con, connection_pool *connPool);
	~connectionRAII();
	
private:
	MYSQL *conRAII;
	connection_pool *poolRAII;
};

#endif
