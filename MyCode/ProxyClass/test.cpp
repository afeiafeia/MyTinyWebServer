
#include <bits/move.h>
class A
{
    int a_;

};

int main()
{
    A a;
    A aa(std::move(a));

    return 0;
}