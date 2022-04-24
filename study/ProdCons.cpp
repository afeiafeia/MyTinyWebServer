
#include <pthread.h>
#include <bits/pthreadtypes.h>
#include <vector>

const int maxNum = 512;
std::vector<int> nums;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int item = 0;
void* Producer(void* ptr)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(nums.size()>=maxNum)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        nums.push_back(item);
        ++item;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

}


void* Consumer(void* ptr)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(nums.empty())
        {
            pthread_cond_wait(&cond,&mutex);
        }
        nums.pop_back();
        --item;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

}

int main()
{
    pthread_t prod;
    pthread_t cons;
    pthread_create(&prod,NULL,&Producer,NULL);
    pthread_create(&cons,NULL,&Consumer,NULL);

    pthread_join(prod,NULL);
    return 0;
}