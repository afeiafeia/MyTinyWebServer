
//使用局部静态变量实现懒汉模式的单例
//C++11标准保证了静态变量的创建是线程安全的
#ifndef SINGLETON_H
#define SINGLETON_H
class mySingleTon
{
private:
    mySingleTon();
public:
    static mySingleTon* GetInstance();
};
#endif