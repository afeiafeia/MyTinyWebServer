#include<iostream>
using namespace std;

//C++ Primer    P352&&P508
int main()
{
    int  a=0;

    //auto f = [a]{return ++a;};   //错误，编译器生成的类中，捕获的变量是其成员函数，默认情况下，重载的调用运算符是const成员函数，因此函数体中不能改变捕获的值

    auto f = [a]  (int x)->int 
    {
        return ++a;
    };//正确，x是参数，并不是成员变量

    //提供要使得重载的调用运算符不是const成员函数,可以在参数列表后面加上mutable关键字
    auto f = [a]  (int x)mutable->int 
    {
        return ++a;
    };//正确，函数调用运算符不是const成员函数，注意mutable的位置！！！！
    int b=1;

}