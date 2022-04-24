#include "unpipc.h"

#define MAXITEM  11000000
#define MAXTHREAD 10

struct
{
    pthread_mutex_t mutex;
    int buff[MAXITEM];
    int curIndex;
    int curVal;
} share = {PTHREAD_MUTEX_INITIALIZER};


void Producer(void* );
void Consumer(void* ); 
int main(int argc,char** argv)
{
    int i=0;
    int Count[MAXTHREAD] = {0};
    pthread_t tid_Producer[MAXTHREAD];
    pthread_t tid_Consumer;

    set_concurrency(MAXTHREAD);
    for(i=0;i<MAXTHREAD;i++)
    {
        pthread_create(&tid_Producer[i],NULL,Producer,&Count[i]);
    }
    pthread_create(&tid_Consumer,NULL,Consumer,NULL);

    int sum = 0;
    for(i=0;i<MAXTHREAD;i++)
    {
        pthread_join(tid_Producer[i],NULL);
        sum+=Count[i];
        printf("Count[%d] = %d\n",i,Count[i]);
    }
    printf("Sum = %d\n",sum);

    pthread_join(tid_Consumer,NULL);

    exit(0);

}

void Producer(void *arg)
{
    for(;;)
    {
        pthread_mutex_lock(&share.mutex);
        if(share.curIndex>=MAXITEM)
        {
            pthread_mutex_unlock(&share.mutex);
            return;
        }
        share.buff[share.curIndex] = share.curVal;
        share.curIndex++;
        share.curVal++;
        pthread_mutex_unlock(&share.mutex);
        *((int*)arg) += 1;
    }
}

void Consumer_Wait(int i)
{
    for(;;)
    {
        pthread_mutex_lock(&share.mutex);
        if(i<share.curIndex)
        {
            pthread_mutex_unlock(&share.mutex);
            return;
        }
        pthread_mutex_unlock(&share.mutex);

    }
}
void Consumer(void* arg)
{
    for(int i=0;i<MAXITEM;i++)
    {
        Consumer_Wait(i);
        if(share.buff[i]!=i)
        {
            printf("buff[%d] = %d\n",i,share.buff[i]);
        }
    }

    return ;
}tval >0 返回接收到的数据的实际大小
     *      @retval =0 被关闭
     *      @retval <0 出现流错误
     */
    virtual int readFixSize(ByteArray::ptr ba, size_t length);

    /**
     * @brief 写数据
     * @param[in] buffer 写数据的内存
     * @param[in] length 写入数据的内存大小
     * @return
     *      @retval >0 返回写入到的数据的实际大小
     *      @retval =0 被关闭
     *      @retval <0 出现流错误
     */
    virtual int write(const void* buffer, size_t length) = 0;

    /**
     * @brief 写数据
     * @param[in] ba 写数据的ByteArray
     * @param[in] length 写入数据的内存大小
     * @return
     *      @retval >0 返回写入到的数据的实际大小
     *      @retval =0 被关闭
     *      @retval <0 出现流错误
     */
    virtual int write(ByteArray::ptr ba, size_t length) = 0;

    /**
     * @brief 写固定长度的数据
     * @param[in] buffer 写数据的内存
     * @param[in] length 写入数据的内存大小
     * @return
     *      @retval >0 返回写入到的数据的实际大小
     *      @retval =0 被关闭
     *      @retval <0 出现流错误
     */
    virtual int writeFixSize(const void* buffer, size_t length);

    /**
     * @brief 写固定长度的数据
     * @param[in] ba 写数据的ByteArray
     * @param[in] length 写入数据的内存大小
     * @return
     *      @retval >0 返回写入到的数据的实际大小
     *      @retval =0 被关闭
     *      @retval <0 出现流错误
     */
    virtual int writeFixSize(ByteArray::ptr ba, size_t length);

    /**
     * @brief 关闭流
     */
    virtual void close() = 0;
};

}

#endif
