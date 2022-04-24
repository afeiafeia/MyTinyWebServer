#include <iostream>

class A
{
public:
	int m_a;
};

class B:virtual public A
{
public:
	long double m_b;
};

class C :virtual public A
{
public:
	int m_c;
};

class D :public B, public C
{
public:
	int m_d;
};

int main()
{
    D d;
    std::cout<<&d<<'\t'<<&d.m_a<<'\t'<<&d.m_b<<'\t'<<&d.m_c<<'\t'<<&d.m_d<<std::endl;
    std::cout<<sizeof(D)<<std::endl;
    std::cout<<sizeof(B)<<std::endl;
    std::cout<<sizeof(C)<<std::endl;
}
