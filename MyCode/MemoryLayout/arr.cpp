#include <iostream>
#include <stdlib.h>
int main()
{
    void* a = malloc(sizeof(int)*10);
    int* b =(int*)a;
    //b[10]=1;
    free(a);
    int* c=b+10;

    std::cout<<*c<<'\n';
    system("pause");
    return 0;
} 