#include "../src/algobase.h"
#include "../src/iterator.h"
#include <iostream>
#include <bits/stl_algo.h>
int main()
{

    int arr[10] = {2, 4, 6, 7, 9, 10, 1, 5, 3, 8};
    //std::sort(&arr[0], &arr[10], std::less<int>());
    mystl::sort(&arr[0],&arr[10],mystl::less<int>());
   // std::cout << arr << std::endl;
    for (int i = 0; i < 10;i++)
    {
        std::cout << arr[i] << std::endl;
    }
    system("pause"); 
    return 0;
}