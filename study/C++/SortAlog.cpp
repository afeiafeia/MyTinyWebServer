#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
//快排
void QuickSort(std::vector<int> &nums,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int tmp = nums[l];
    int i = l;
    int j = r;
    while(i<j)
    {
        while(i<j&&nums[j]>=tmp)
        {
            --j;
        }
        while(i<j&&nums[i]<=tmp)
        {
            ++i;
        }
        std::swap(nums[i],nums[j]);
    }
    std::swap(nums[i],nums[l]);
    QuickSort(nums,l,i-1);
    QuickSort(nums,i+1,r);
}


//快排迭代版本
void QuickSort2(std::vector<int> &nums,int l,int r)
{

    std::stack<std::pair<int,int>> s;
    s.push({l,r});
    while(!s.empty())
    {
        std::pair<int,int> T = s.top();
        s.pop();
        int curL = T.first;
        int curR = T.second;
        int tmp = nums[curL];
        while(curL<curR)
        {
            while(curL<curR&&nums[curR]>=tmp)
            {
                curR--;
            }
            while(curL<curR&&nums[curL]<=tmp)
            {
                curL++;
            }
            std::swap(nums[curL],nums[curR]);
        }
        std::swap(nums[curL],nums[T.first]);
        if(T.first<curL-1)
        {
            s.push({T.first,curL-1});
        }
        if(curL+1<T.second)
        {
            s.push({curL+1,T.second});
        }
    }
}

void MergeSort(std::vector<int> &nums,int l,int r)
{
    if(l>=r)
    {
        return ;
    }
    int mid = (l+r)>>1;
    MergeSort(nums,l,mid);
    MergeSort(nums,mid+1,r);
    int size = r-l+1;
    std::vector<int> tmp(size);
    int x = l;
    int y = mid+1;
    int z = 0;
    while(x<=mid&&y<=r)
    {
        if(nums[x]<nums[y])
        {
            tmp[z] = nums[x];
            x++;
        }
        else
        {
            tmp[z] = nums[y];
            y++;
        }
        z++;
    }
    while(x<=mid)
    {
        tmp[z] = nums[x];
        x++;
        z++;
    }
    while(y<=r)
    {
        tmp[z] = nums[y];
        y++;
        z++;
    }
    for(int i=l;i<=r;i++)
    {
        nums[i] = tmp[i-l];
    }

}

void BubbleSort(std::vector<int> &nums)
{
    int size = nums.size();
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i=0;i<size-1;++i)
        {
            if(nums[i]>nums[i+1])
            {
                sorted = false;
                std::swap(nums[i],nums[i+1]);
            }
        }
        --size;
    }
}

void SelectSort(std::vector<int> &nums)
{
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        int tar = nums[i];
        int minIndex=  i;
        for(int j = i+1;j<size;j++)
        {
            if(nums[j]<tar)
            {
                tar = nums[j];
                minIndex = j;
            }
        }
        std::swap(nums[i],nums[minIndex]);
    }

}

void InsertSort(std::vector<int> &nums)
{
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        int tar = nums[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(nums[j]>tar)
            {
                nums[j+1] = nums[j];
            }
            else
            {
                break;
            }
        }
        nums[j+1] = tar;
    }
}



void HeapSort(std::vector<int> &nums)
{
    std::priority_queue<int,std::vector<int>,std::greater<int>> heap(nums.begin(),nums.end());
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        nums[i] = heap.top();
        heap.pop();
    }
}

void make_heap(std::vector<int> &nums,int st,int ed)
{
    int lastIndex = ed;
    int fatherIndex = (lastIndex-1)>>1;
   for(int i=fatherIndex;i>=0;--i) 
    {
        int curFather = i;
        int childIndex = 2*curFather+1;
        while(childIndex<=ed)
        {
            if(childIndex+1<=ed&&nums[childIndex]<nums[childIndex+1])
            {
                childIndex++;
            }
            if(nums[childIndex]>nums[curFather])
            {
                std::swap(nums[childIndex],nums[curFather]);
                
                curFather = childIndex;
                childIndex = 2*curFather+1;
            }
            else
            {
                break;
            }
        }
    }
}

void HeapSort2(std::vector<int> &nums)
{
    int n = nums.size();
    for(int i=n-1;i>=0;i--)
    {
        make_heap(nums,0,i);
        std::swap(nums[0],nums[i]);
    }
}

int Fun(std::vector<int> &nums)
{
    const int minVal = -1000000;
    int n = nums.size();
    std::vector<int> dp1(n,0);
    dp1[0] = nums[0];
    std::vector<int> preMax(n,minVal);
    preMax[0] = dp1[0];
    for(int i = 1;i<n;i++)
    {
        dp1[i] = dp1[i-1]>0?dp1[i-1]+nums[i]:nums[i];
        preMax[i] = preMax[i-1]>dp1[i]?preMax[i-1]:dp1[i];
    }
    std::vector<int> dp2(n,0);
    dp2[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        dp2[i] = dp2[i+1]>0?dp2[i+1]+nums[i]:nums[i];
    }
    int res = preMax[n-1];
    for(int i=0;i<n-1;i++)
    {
        int tmp = preMax[i]+dp2[i+1];
        if(tmp>res)
        {
            res = tmp;
        }
    }
    return res;


}

int main()
{
    std::vector<int> nums = {0,0,0,0,2,3,1,6,4,9,0,5,8,7};

    //MergeSort(nums,0,nums.size()-1);

    //QuickSort(nums,0,nums.size()-1);

    //BubbleSort(nums);

    //InsertSort(nums);
    
    //SelectSort(nums);

    //QuickSort2(nums,0,nums.size()-1);

    //HeapSort(nums);
    HeapSort2(nums);

    std::vector<int> arr = {-1,3,-5,2,-1,3};
    int res = Fun(arr);

    return 0;


}