#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H
namespace afa
{
    class noncopyable
    {
    protected:
        noncopyable(){}
        ~noncopyable(){}
    public:
        noncopyable(const noncopyable &rhs){}
        const noncopyable& operator=(const noncopyable &rhs){}
    };
}
#endif
