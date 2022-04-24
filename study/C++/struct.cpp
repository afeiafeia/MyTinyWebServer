#include<iostream>
//#pragma pack(4)
struct T
{
    long double m;
    char l;
};
struct A
{
    //char x;
    //long double a;
    //double b;
    int a;
    T t;
};
class Parent2
{
    //int p2;
public:
    int c;
    struct B
    {
        int a;
        double x;
        
    };
    B b;

    //virtual void fun2(){};
};

int main()
{
    A aa;
    std::cout<<sizeof(A)<<std::endl;
    std::cout<<&aa<<'\t'<<&aa.t<<std::endl;

    Parent2 p;
    std::cout<<sizeof(Parent2)<<std::endl;
    std::cout<<&p<<'\t'<<&p.b.x<<std::endl;
}