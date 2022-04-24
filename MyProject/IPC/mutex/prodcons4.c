#include "unpipc.h"

#define MAXITEM 100
#define MAXTHREAD 2
struct 
{
   pthread_mutex_t mutex;
   pthread_cond_t cond;
   int nReady;
   int buff[MAXITEM];
   int curIndex;
   int curVal;
} share = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_COND_INITIALIZER};


void Producer(void*);
void Consumer(void*);
int main(int argc,char** argv)
{
    int i=0;
    printf("test main %d\n",MAXITEM);
    pthread_t tid_Producer[MAXTHREAD];
    pthread_t tid_Consumer;

    set_concurrency(MAXTHREAD);
    int count[MAXTHREAD];
    for(i=0;i<MAXTHREAD;i++)
    {
        pthread_create(&tid_Producer[i],NULL,Producer,&count[i]);

    }
    pthread_create(&tid_Consumer,NULL,Consumer,NULL);

    for(i=0;i<MAXTHREAD;i++)
    {
        pthread_join(tid_Producer[i],NULL);
        //printf("Count[%d] = %d\n",i,count[i]);
    }
    pthread_join(tid_Consumer,NULL);


    exit(0);

}

void Producer(void* arg)
{
    for(int i=0;;i++)
    {
        pthread_mutex_lock(&share.mutex);
        while(share.curIndex>=MAXITEM)
        {
            printf("Producer Wait %d\n",share.curIndex);
            pthread_cond_wait(&share.cond,&share.mutex);
            //pthread_mutex_unlock(&share.mutex);
            //return NULL;
        }
        if(i==50)
        pthread_exit(0);
        share.buff[share.curIndex] = share.curVal;
        share.curIndex++;
        share.curVal++;
        printf("Produce %d\n",share.curIndex);
        if(share.curIndex==1)
        {
            //share.nReady++;
            //share.curIndex++;
            printf("Wake Up Consumer %d\n",share.curIndex);
            Pthread_cond_broadcast(&share.cond);
        }
        share.nReady++;
        pthread_mutex_unlock(&share.mutex);

    }
}

void Consumer(void* arg)
{
    for(;;)
    {
        pthread_mutex_lock(&share.mutex);
        while(share.curIndex==0)
        {
            printf("Consumer Wait %d\n",share.curIndex);
            pthread_cond_wait(&share.cond,&share.mutex);
        }
        if(share.curIndex==MAXITEM)
        {
            //share.curIndex--;
            printf("Wake Up Producer %d\n",share.curIndex);
            Pthread_cond_broadcast(&share.cond);
        }
        //share.nReady--;
        share.curIndex--;
        //printf("Consume %d\n",share.curIndex);
        pthread_mutex_unlock(&share.mutex);
    }
}