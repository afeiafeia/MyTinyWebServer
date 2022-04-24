#include <vector>
#include <algorithm>
using namespace std;

int FindNum(std::vector<int> &nums,int target)
{
    int l=0;
    int r = nums.size()-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]<target)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return -1;
}
int MinMax(int num,std::vector<int> &nums)
{
    std::vector<int> bits;
    int tmp = num;
    int maxBit = 0;
    while(tmp)
    {
        int last = tmp%10;
        bits.push_back(last);
        tmp = tmp/10;
    }
    reverse(bits.begin(),bits.end());
    std::sort(nums.begin(),nums.end());
    int minNum = nums[0];
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<minNum)
        {
            minNum = nums[i];
        }
    }
    if(minNum>bits[0])
    {
        int n = bits.size()-1;
        int res = 0;
        while(n)
        {
            res = res+minNum*10;
        }
    }
    int res = 0;
    bool flag = false;
    for(int i=0;i<bits.size();i++)
    {
        int curNum = bits[i];
        int curMinMax = -1;
        int curMinIndex = -1;
        int curRes = 0;
        for(int j=0;j<nums.size();j++)
        {
            if(curNum>=nums[j])
            {
                if(nums[j]>curMinMax)
                {
                    curMinMax = nums[j];
                    curMinIndex = j;
                }
            }

        }
        if(curMinMax>=0)
        {
            curRes = curMinMax;
        }
        else
        {
            //没找到小于curNum的数值
            flag = true;
            //前面的数一直是==
            if(i>1)
            {
                int cur = res%10;
                int index = FindNum(nums,cur);
                res = res/10;
                res = res*10+nums[index-1];
                curRes = nums.back();

            }
            else
            {
                i=0;
                res = 0;
                curRes = 0;
            }
        }
        if(!flag)
        {
            res = res*10+curRes;
            if(curRes<curNum)
            {
                flag = true;
                i++;
                curRes = nums.back();
            }
        }
        if(flag)
        {
            res = res*10+curRes;
            i++;
            while(i<bits.size())
            {
                res = res*10+nums.back();
                i++;
            }
        }

    }

    return res;

}

int main()
{
    int num = 21124;
    vector<int> nums = {2,4,9};
    int res = MinMax(num,nums);

    system("pause");
    return 0;
}