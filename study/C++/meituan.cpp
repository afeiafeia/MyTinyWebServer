#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//第二题：给你一个数组，可以在任意位置翻转一次，也可以不反转，求连续最大和

int MaxSum(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> PreSum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        PreSum[i] = PreSum[i-1]+nums[i-1];//前缀和
    }
    vector<int> dp1(n,0);
    dp1[0]=nums[0];
    vector<int> maxPre(n,0);
    maxPre[0] = nums[0];
    for(int i=1;i<n;i++)
    {
        if(dp1[i-1]>0)
        {
            dp1[i] = dp1[i-1]+nums[i];
        }
        else
        {
            dp1[i] = nums[i];
        }
        maxPre[i] = max(maxPre[i-1],dp1[i]);
    }
    vector<int> dp2(n,0);
    dp2[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(dp2[i+1]>0)
        {
            dp2[i] = dp2[i+1]+nums[i];
        }
        else
        {
            dp2[i] = nums[i];
        }
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res = max(res,maxPre[i]+dp2[i+1]);
    }
    return res;
}


//第四题
//给定一个数组，可以任意调整数组的顺序，之后对于数组，可以查询一个范围内的数字的和，可以对一个范围内的数字加上一个指定值k，求查询得到的范围和的总和的最大值
int MaxRegionSum(vector<int> &nums,vector<vector<int>> &region,vector<int> AddSum) 
{
    int numRegion = region.size();
    int n = nums.size();
    vector<int> QueryTime(n,0);
    for(int i=0;i<numRegion;i++)
    {
        for(int j=region[i][0];j<=region[i][1];j++)
        {
            QueryTime[j]++;
        }
    }
    
    sort(nums.begin(),nums.end(),greater<int>());
    sort(QueryTime.begin(),QueryTime.end(),greater<int>());
    int sum = 0;
    for(int i=0;i<QueryTime.size();i++)
    {
        int time = QueryTime[i];
        sum = sum+nums[i]*time+AddSum[i];
    }
    return sum;

}


//int main()
//{
//    vector<int> nums = {3,4,2,1,5};
//    vector<vector<int>> region ;
//    vector<vector<int>> addK(5,vector<int>(5,0));
//    addK[2][3] = 2;
//    addK[1][2] = 2;
//    int n = 0;
//    int m = 0;
//    cin>>n>>m;
//    int size = n;
//    while(n--)
//    {
//        cin>>nums[n];
//    }
//    vector<int> QueryTime(size,0);
//    vector<vector<int>> AddNum(size);
//    vector<int> AddSum(size,0);
//    while(m--)
//    {
//        int flag = 0;
//        cin>>flag;
//        if(flag==1)
//        {
//            int l = 0;
//            int r = 0;
//            cin>>l>>r;
//            
//            region.push_back({l-1,r-1});
//            for(int i=l-1;i<r;i++)
//            {
//                QueryTime[i]++;
//                if(QueryTime[i]==1)
//                {
//                    continue;
//                }
//                int num = AddNum.size();
//                for(int j=0;j<num;j++)
//                {
//                    AddSum[i]+= AddNum[i][j];
//                }
//            }
//            
//        }
//        else if(flag==2)
//        {
//            int l = 0;
//            int r = 0;
//            int k = 0;
//            cin>>l>>r>>k;
//            addK[l-1][r-1] = k;
//            for(int i=l-1;i<r;i++)
//            {
//                AddNum[i].push_back(k);
//            }
//        }
//    }
//    int res = MaxRegionSum(nums,region,AddSum);
//
//    cout<<res<<endl;
//    system("pause");
//
//    return 0;
//}




struct ListNode1
{
    pair<int,int> val;
    ListNode1* prev;
    ListNode1* next;

    ListNode1()
    :val({0,0})
    ,prev(nullptr)
    ,next(nullptr)
    {
    }

    ListNode1(pair<int,int> value)
    :val(value)
    ,prev(nullptr)
    ,next(nullptr)
    {
    }

    ListNode1(pair<int,int> value,ListNode1* pre,ListNode1* nxt)
    :val(value)
    ,prev(pre)
    ,next(nxt)
    {
    }

};


class LRUCache {

private:
    unordered_map<int,ListNode1*> m;
    ListNode1* head;
    ListNode1* tail;
    int cap;
    int size;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        ListNode1* curNode = new ListNode1();
        head=curNode;
        for(int i=1;i<cap;i++)
        {
            ListNode1* tmpNode = new ListNode1();
            curNode->next = tmpNode;
            tmpNode->prev = curNode;
            curNode = tmpNode;
        }
        tail = head;

    }
    
    int get(int key) {
        if(m.find(key)==m.end())
        {
            return -1;
        }
        ListNode1* tarNode = m[key];
        RemoveNode(tarNode);
        tarNode->next = head;
        tarNode->prev = nullptr;
        head->prev = tarNode;
        head = tarNode;
        return head->val.second;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            ListNode1* tarNode = m[key];
            RemoveNode(tarNode);
            tarNode->next = head;
            tarNode->prev = nullptr;
            head = tarNode;
            head->val.second = value;
        }
        else
        {
            ListNode1* tmpNode = nullptr;
            if(size<cap)
            {
                size++;
                tmpNode = tail;
                if(tail->next!=nullptr)
                {
                    tail = tail->next;
                }
            }
            else
            {
                tmpNode = tail;
                tail = tail->prev;
            }
            tmpNode->val = {key,value};
            RemoveNode(tmpNode);
            tmpNode->next = head;
            tmpNode->prev = nullptr;
            head->prev = tmpNode;
            head = tmpNode;
            m[key] = tmpNode;
        }
    }

    void RemoveNode(ListNode1* cur)
    {
        ListNode1* preNode = cur->prev;
        ListNode1* nextNode = cur->next;
        if(preNode==nullptr)
        {
            head = nextNode;
            return;
        }
        preNode->next = nextNode;
        if(nextNode==nullptr)
        {
            tail = preNode;
            return;
        }
        nextNode->prev = preNode;
        
    }
};

int main()
{
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,2);
    lru.get(1);
    lru.put(3,3);
    lru.get(2);


    system("pause");
    return 0;
}