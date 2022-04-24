//#pragma pack(1)
#include "stdio.h"
struct
{
    int a;
    char b;
    char c;
}T1;

struct
{
    char a;
    double b;
    int c;
}T2;

struct
{
    char a;
    char b;
    int c;
}T3;

struct
{
    //char a;
    //short b;
    //int c;
    //int d;
    double e;
    char f;
}T4;

class Blank
{

};

int main()
{
    //T1 t1;
    //T2 t2;
    //T3 t3;
    //T4 t4;

    //std::cout<<sizeof(t1)<<std::endl;
    //std::cout<<sizeof(t2)<<std::endl;
    //std::cout<<sizeof(t3)<<std::endl;
    //std::cout<<sizeof(t4)<<std::endl;


    //printf("%d\n",sizeof(long));
    //printf("%d\n",sizeof(T2));
    //printf("%d\n",sizeof(T3));
    //printf("%d\n",sizeof(T4));
    printf("%d\n",sizeof(Blank));
}

