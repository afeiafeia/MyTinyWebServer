#include <sys/types.h>
#include <sys/stat.h>

#include "unpipc.h"

#define FIFO1  "/tmp/fifo1.1"
#define FIFO2  "/tmp/fifo2.2"

int main(int argc,char** argv)
{
    int readfd;
    int writefd;
    pid_t childPid;

    if (mkfifo(FIFO1,FILE_MODE)<0&&errno!=EEXIST)
    {
       err_sys("Create Fifo Failed!"); /* code */
    }
    if (mkfifo(FIFO2,FILE_MODE)<0&&errno!=EEXIST)
    {
        err_sys("Create Fifo Failed!");
        /* code */
    }

    if ((childPid = fork())!=0)
    {
        readfd = open(FIFO1,O_RDONLY,0);/* code */
        writefd = open(FIFO2,O_WRONLY,0);

        server(readfd,writefd);
        exit(0);
    }

    writefd = open(FIFO1,O_WRONLY,0);
    readfd = open(FIFO2,O_RDONLY,0);


    client(readfd,writefd);

    waitpid(childPid,NULL,0);


    close(readfd);
    close(writefd);



    unlink(FIFO1);
    unlink(FIFO2);
    exit(0);
    
    
    
}