#include<pthread.h>
#include "unp.h"
#define NUM_THREAD 5

void handleEx(int signo)
{
    
    printf("Exception!!! %s\n");
    //exit(0);
    pthread_exit(NULL);
}
struct thread_data
{
    int id;
    char* message;
};
void* hello(void* threadid)
{
    //signal(SIGSEGV,SIG_IGN);
    int id = *((int*)(threadid));
    printf("Hello World! ThreadID is %d\n",id);
    //threadid = NULL;

    struct thread_data* p=NULL;
    //int a = p->id;
    struct thread_data* x = (struct thread_data*)malloc(sizeof(struct thread_data)*3);

    struct thread_data y[2];
    //int b[5];
    // b[6]=3;
    free(x);
    //printf("Hello World! ThreadID is %s\n",y[5].message);
    id = *((int*)(threadid));
    //printf("Hello World! ThreadID is %d\n",id);
    //std::cout<<"Hello World! ThreadID is"<<id<<std::endl;
    pthread_exit(NULL);
}

void* testStructData(void* threadData)
{

    printf("Count Is:%d",count++);
    //signal(SIGSEGV,handleEx);
    //threadData = NULL;
    //struct thread_data *curData = (struct thread_data*) threadData;
    //int id = *(int*)(threadData);
   //printf("CurThread ID is %d\n",id);
    //std::cout<<"CurThread ID is"<<curData->id<<std::endl;
}

int main(int argc,char** argv)
{
    pthread_t tid[NUM_THREAD];
    int index[NUM_THREAD];
    struct thread_data arrayData[NUM_THREAD];


    int count = 1;


    //signal(SIGSEGV,SIG_IGN);
    //signal(SIGSEGV,handleEx);
    //int* p=NULL;
    //int a = *p;
    for(int i=0;i<NUM_THREAD;i++)
    {
        arrayData[i].id=i;
        arrayData[i].message = (char*)"This is Message";
        index[i]=i;
        //std::cout<<"CreateThread"<<i<<std::endl;
        int ret ;
        if(i==3)
        {
            ret = pthread_create(&tid[i],NULL,hello,(void*)&(index[i]));
        }
        else
        {
            ret = pthread_create(&tid[i],NULL,testStructData,(void*)&(arrayData[i]));
        }
        if(ret!=0)
        {
            printf("error %s\n");
        }


    }

    struct thread_data y[2];
    int *m=NULL;
    //printf("Hello World! ThreadID is %d\n",*m);
    //sleep(5);
    pthread_exit(NULL);
    return 0;

}