#include<vector>
#include <iostream>
//https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
//排序，以下算法都是按照升序排


//1.快速排序
void quick_sort(std::vector<double> &ivctNums,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    double target = ivctNums[left];
    int i = left;
    int j = right;
    while(i<j)
    {
        while(i<j&&ivctNums[j]>=target)
        {
            j--;
        }
        while(i<j&&ivctNums[i]<=target)
        {
            i++;
        }
        std::swap(ivctNums[i],ivctNums[j]);
    }

    std::swap(ivctNums[left],ivctNums[j]);

    quick_sort(ivctNums,left,j-1);
    quick_sort(ivctNums,j+1,right);

}


//2.冒泡排序
void bubble_sort(std::vector<double> &ivctNums)
{
    int size = (int)ivctNums.size();
    for(int i=0;i<size;i++)
    {
        for(int j=size-1;j<i;j--)
        {
            if(ivctNums[j]<ivctNums[j-1])
            {
                std::swap(ivctNums[j],ivctNums[j-1]);
            }
        }
    }
}

//3.归并排序
void merge_sort(std::vector<double> &ivctNums,int left,int right)
{
    if(left>=right)
    return ;
    std::vector<double> vctTmpNums(right-left+1,0.0);
    int mid = (left+right)>>1;
    merge_sort(ivctNums,left,mid);
    merge_sort(ivctNums,mid+1,right);
    int i = 0;
    int firstArrIndex = left;
    int secondArrIndex = mid+1;
    while(firstArrIndex<=mid&&secondArrIndex<=right)
    {
        if(ivctNums[firstArrIndex]<ivctNums[secondArrIndex])
        {
            vctTmpNums[i++] = ivctNums[firstArrIndex++];
        }
        else
        {
            vctTmpNums[i++] = ivctNums[secondArrIndex++];
        }
    }
    while(firstArrIndex<=mid)
    {
        vctTmpNums[i++] = ivctNums[firstArrIndex++];
    }

    while(secondArrIndex<=right)
    {
        vctTmpNums[i++] = ivctNums[secondArrIndex++];
    }

    for(int i=left,j=0;i<=right;i++,j++)
    {
        ivctNums[i] = vctTmpNums[j];
    }

}

//4.插入排序
void insert_sort(std::vector<double> &ivctNums)
{
    int size = ivctNums.size();
    for(int i=1;i<size;i++)
    {
        int target = ivctNums[i];
        int j = i-1;
        while(j>=0&&target<ivctNums[j])
        {
            ivctNums[j+1] = ivctNums[j];
            j--;
        }
        ivctNums[j+1] = target;
    }
}


//5.选择排序
void select_sort(std::vector<double> &ivctNums)
{
    int size = ivctNums.size();
    for(int i=0;i<size;i++)
    {
        int min = i;
        double target = ivctNums[i];
        for(int j=i+1;j<size;j++)
        {
            if(ivctNums[j]<target)
            {
                target = ivctNums[j];
                min = j;
            }
        }
        //ivctNums[i] = target;
        std::swap(ivctNums[i],ivctNums[min]);
    }
}

class A
{
public: 
    A()
    {
        std::cout<<"construct!\n";
    }
    ~A()
    {
        std::cout<<"deconstruct!\n";
    }
    int a;
};

const A& fun()
{
    return A();
}



//腾讯IEG魔方工作室面试题：
struct Item
{
    int key;
    int value;

    bool operator<(const Item& rhs)
    {
        return value<rhs.value;
    }
};

void Quick_Sort(std::vector<Item>& vctItem,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int i = left;
    int j = right;
    Item target = vctItem[left];
    while(i<j)
    {
        while(i<j&&!(target<vctItem[j]))
        {
            j--;
        }
        while(i<j&&!(vctItem[i]<target))
        {
            i++;
        }
        std::swap(vctItem[i],vctItem[j]);
    }
    std::swap(vctItem[left],vctItem[i]);
    Quick_Sort(vctItem,left,i-1);
    Quick_Sort(vctItem,i+1,right);

}

void Merge_Sort(std::vector<Item>& vctItem,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int mid = (left+right)>>1;
    Merge_Sort(vctItem,left,mid);
    Merge_Sort(vctItem,mid+1,right);

    std::vector<Item> vctTmp;
    vctTmp.reserve(right-left+1);
    int l = left;
    int r = mid+1;
    while(l<=mid&&r<=right)
    {
        if(vctItem[r]<vctItem[l])
        {
            vctTmp.push_back(vctItem[l]);
            l++;
        }
        else
        {
            vctTmp.push_back(vctItem[r]);
            r++;
        }
    }
    if(l<=mid)
    {
        vctTmp.insert(vctTmp.end(),vctItem.begin()+l,vctItem.begin()+mid+1);
    }
    else if(r<=right)
    {
        vctTmp.insert(vctTmp.end(),vctItem.begin()+r,vctItem.end());
    }

    for(int i=left,j=0;i<=right;i++,j++)
    {
        vctItem[i] = vctTmp[j];
    }


}

void Insert_Sort(std::vector<Item> &vctItem)
{
    int n = vctItem.size();
    for(int i=1;i<n;i++)
    {
        Item target = vctItem[i];
        int j = i-1;
        for(;j>=0;j--)
        {
            if(vctItem[j]<target)
            {
                vctItem[j+1] = vctItem[j];
            }
            else
            {
                break;
            }
        }
        vctItem[j+1] = target;
    }
}




int main()
{
    A();
    const A& aaa = A();
    int x = 10;
    const int * pp = nullptr;
    
    {
        //const int& a = int(100);
        //const int * p = &a;
        //pp= &a;

    }

    //int y = *pp;
    //const int * p = &a;


    //int b =a;



    std::vector<double> arr = {1,4,7,2,8,10,5,3,11};
   // std::vector<double> arr = {1,8,7,6};

    //quick_sort(arr,0,arr.size()-1);

    select_sort(arr);

    //insert_sort(arr);

    //merge_sort(arr,0,arr.size()-1);

    std::vector<Item> vctItem = {
        {2,4},
        {3,6},
        {4,7},
        {6,2},
        {5,10},
        {3,0}
    };

    Quick_Sort(vctItem,0,5);

    //Merge_Sort(vctItem,0,5);

    //Insert_Sort(vctItem);

    return 0;
}