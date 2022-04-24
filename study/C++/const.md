## 为什么常量对象或者常量引用不能调用非常量成员函数？*C++ Primer p231*
```c++
class A
{
    int a_;
    int GetA()
    {
        return a_;
    }
    void Fun(const A &rhs)
    {
        rhs.GetA();//错误
    }
};
```
成员函数有一个隐式的this指针形参，在调用成员函数时，会将调用对象的地址传给该this指针，
默认情况下，该this指针是常量指针（顶层const，指针本身是一个常量，A* const this）,
而常量或者常量引用是常量，因此一定要使用底层const，例如常量引用或者指向常量的指针（指针常量const A*）绑定到其上面,而常量指针是顶层const，无法绑定
需要在函数后面加上const（常量成员函数）
```c++
class A
{
    int a_;
    int GetA()const
    {
        return a_;
    }
    void Fun(const A &rhs)
    {
        rhs.GetA();//正确
    }
};
```
这个const是修饰this指针的，使其成为const A* const,如果便可以绑定到const对象上
对于指针常量（const A*），不能通过指针修改所指对象的成员，这也就是为什么const修饰的函数中不能更改对象的成员

