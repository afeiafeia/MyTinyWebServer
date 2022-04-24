#include <iostream>
#include <pthread.h>
#include <bits/pthreadtypes.h>
int single = 1;
int doub = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool IsSingle = false;
void* PrintSingle(void* ptr)
{
    while(single<100)
    {
        pthread_mutex_lock(&mutex);
        while(!IsSingle)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        std::cout<<single<<std::endl;
        single+=2;
        IsSingle = false;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;

}

void* PrintDoub(void* ptr)
{
    while(doub<=100)
    {
        pthread_mutex_lock(&mutex);
        while(IsSingle)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        std::cout<<doub<<std::endl;
        doub+=2;
        IsSingle = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;

}

int main()
{
    pthread_t sing;
    pthread_t doub;
    pthread_create(&sing,NULL,&PrintSingle,NULL);
    pthread_create(&doub,NULL,&PrintDoub,NULL);

    pthread_join(sing,NULL);
    pthread_join(doub,NULL);
    return 0;
}