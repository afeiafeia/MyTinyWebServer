
#include <iostream>
#define FILENAME "./test_buff.txt"

int main()
{
    FILE* fp = fopen(FILENAME,"a");

    char buff[400];
    setbuf(fp,buff);

    char readBuff[20];
    //fgets(readBuff,20,fp);
    //char maxBuff[20] = "张阿飞";
    char maxBuff[20] = "12";
    fputs(maxBuff,fp);
    //fflush(fp);
    return 0;
}