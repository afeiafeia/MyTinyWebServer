#include "../src/heap.h"
#include <vector>
int main()
{

    std::vector<int> arr= {2,4,7,9,10,34};
    mystl::heap<int> heap;

    heap.make_heap(&arr[0],&arr.back());


    return 0;




    
}