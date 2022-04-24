#ifndef MEMORY_LAYOUT_H
#define MEMORY_LAYOUT_H

class Parent1
{
private:
    int m_a;

public:
    //int GetA()
    //{
    //    return m_a;
    //}
//
    //int SetA(int a)
    //{
    //    m_a = a;
    //}

    //virtual void fun1(){};
};

class Parent2
{
    //int p2;
    int c;
    //struct A
    //{
    //    int a;
    //    double x;
    //    
    //};
    //A a;

    //virtual void fun2(){};
};

class Child: public Parent1
{
    int c1;
    double d;
    //virtual void cFun1(){}
};








#endif