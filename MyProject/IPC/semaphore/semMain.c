
#include "unpipc.h"
//#include "bits/semaphore.h"
//#include "bits/pthreadtypes.h"
//#include "pthread.h"
//#include "asm-generic/fcntl.h"
#define NBUFF 10

#define SEM_MUTEX   "mutex"
#define SEM_NEMPTY  "nempty"
#define SEM_NSTORED "nstored"

struct semMain
{
    sem_t* mutex;
    sem_t* nempty;
    sem_t* nstored;

    int buff[NBUFF];
} shared;

void* producer(void* );
void* consumer(void* );

int main(int argc,char** argv)
{
    pthread_t tid_producer;
    pthread_t tid_consumer;
    //printf("produce buff[%d]\n",NBUFF);
    shared.mutex   = sem_open(Px_ipc_name(SEM_MUTEX),O_CREAT|O_EXCL,FILE_MODE,1);
    shared.nempty  = sem_open(Px_ipc_name(SEM_NEMPTY),O_CREAT|O_EXCL,FILE_MODE,NBUFF);
    shared.nstored = sem_open(Px_ipc_name(SEM_NSTORED),O_CREAT|O_EXCL,FILE_MODE,0);
    if(shared.mutex==NULL
    ||shared.nempty==NULL
    ||shared.nstored==NULL)
    {
        printf("open sem failed!\n");
        return 0;
    }
    
    set_concurrency(2);
    pthread_create(&tid_producer,NULL,producer,NULL);    
    //pthread_create(&tid_consumer,NULL,consumer,NULL);    
    printf("produce buff[%d]\n",NBUFF);
    pthread_join(tid_producer,NULL);
    //pthread_join(tid_consumer,NULL);
    //printf("produce buff[&d]\n",NBUFF);
    sem_unlink(Px_ipc_name(SEM_MUTEX));
    sem_unlink(Px_ipc_name(SEM_NEMPTY));
    sem_unlink(Px_ipc_name(SEM_NSTORED));

    exit(0);
}

void* producer(void* arg)
{
    for(int i=0;i<NBUFF;i++)
    {
        printf("produce buff[%d] = %d\n",i%NBUFF,shared.nempty);
        //sem_wait(shared.nempty);
        //sem_wait(shared.mutex);
        ////shared.buff[i%NBUFF] = i;
        ////printf("produce buff[%d] = %d\n",i%NBUFF,i);
        //sem_post(shared.mutex);
        //sem_post(shared.nstored);
    }
}

void* consumer(void* arg)
{
    for(int i=0;i<NBUFF;i++)
    {
        sem_wait(shared.nstored);
        sem_wait(shared.mutex);
        if(shared.buff[i%NBUFF] != i)
        {
            printf("buff[&d] = %d\n",i,shared.buff[i%NBUFF]);
        }
        else
        {
            printf("consumer buff[%d] = %d\n",i%NBUFF,i);
        }
        sem_post(shared.mutex);
        sem_post(shared.nempty);
    }
}