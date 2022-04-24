#include "SharedPtr.h"
#include "AutoPtr.h"
#include <iostream>
#include <tr1/shared_ptr.h>
//int SharedPtr<int>::count = 0;
class Base
{
    private:
    int m_base;
    public:
    virtual int GetBase()
    {
        return m_base;
    }
};

class Drived:public Base
{
private:
    int m_drived;
public:
    int GetDrived()
    {
        return m_drived;
    }

};

void fun(SharedPtr<int> p)
{
    int sa;
    int a = 0;

    return ;
}

int main()
{
    shared_ptr<Base> b = make_shared<Drived>(new Drived());

    shared_ptr<Drived> d = make_shared<Drived>(new Drived());
    d = b;

    shared_ptr<int> a = make_shared<Drived>(new int(5));

    b = a;



}


int mainMyPtr()
{
    SharedPtr<int> p = new int(100);//调用SharedPtr(T* ptr)构造

    int s =2;

    int ss = std::move(s);
    int* ps = &s;
    int* pss = &ss;
    //最好不要用下面的写法
    //SharedPtr<int> p2;

    p = new int(11);

   // SharedPtr<int> p2 = p;
    fun(p);
    std::cout<<*p<<std::endl;

    Base* b = new Drived();//基类指针指向派生类对象
    Drived* d = new Drived();//基类指针指向派生类对象
    Base& bb = *d;
    Drived& dd = dynamic_cast<Drived&>(bb);

    //Drived* d = dynamic_cast<Drived*>(b);
    //d = dynamic_cast<Drived*> (b);


    SharedPtr<Base> Base_ptr = new Drived();
    SharedPtr<Drived> Drived_ptr = new Drived();
    int * t;
    Base_ptr = Drived_ptr;
    Base_ptr = b;
    if(Base_ptr)
    {
        int a=2;
    }
    //Base_ptr = t;//不行
   // Base_ptr = SharedPtr<Base>::UpCast(Drived_ptr);//实现派生类智能指针转换成基类智能指针
    //Base_ptr = Drived_ptr;

   { 
    SharedPtr<Base> Base_ptrTest = new Drived();
    Drived_ptr = SharedPtr<Drived>::DownCast(Base_ptrTest);
    int a=0;
   }
    Drived_ptr = SharedPtr<Drived>::DownCast(b);
    //Base_ptr = SharedPtr<Base>::DownCast(p);//不能继承关系就不能转
    
    //Drived_ptr = Base_ptr;
    //Drived_ptr = p;


    int* p1 = static_cast<int*>(static_cast<void*>(b));
    //int* p2 = d;




    system("pause");
    return 0;




}