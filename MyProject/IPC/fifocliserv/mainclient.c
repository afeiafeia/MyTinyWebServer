#include "fifo.h"

int main(int argc,char** argv)
{
    int readfifo;
    int writefifo;
    size_t len;
    ssize_t n;

    char* ptr = NULL;
    char fifoname[MAXLINE];
    char buff[MAXLINE];
    pid_t pid;

    //pid = getpid();

    if ((mkfifo(FIFO1,FILE_MODE))<0&&errno!=EEXIST)
    {
        err_sys("create fifo1 failed!");/* code */
    }


    


    if((ptr=fgets(buff,MAXLINE,stdin))==NULL)
    err_sys("fgets error!");

    len = strlen(buff);
    //if(buff[len-1]=='\n')
    //buff[len-1]='\0';

    writefifo = open(SERV_FIFO,O_WRONLY,0);
    readfifo = open(FIFO1,O_RDONLY,0);
    if(write(writefifo,buff,len)!=len)
    err_sys("write name falied!!!");



    while((n=read(readfifo,buff,MAXLINE))>0)
    {
        write(STDOUT_FILENO,buff,n);
    }

    close(readfifo);
    unlink(FIFO1);
    exit(0);

}