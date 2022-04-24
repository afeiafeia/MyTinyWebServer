#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        int size = arr.size();
        int minValue = INT_MAX;
        for(int i=0;i<size;i++)
        {
            if(arr[i]<minValue)
            {
                minValue = arr[i];
            }
        }
        map<int,int> mp;
        for(int i=0;i<size;i++)
        {
            int curIndex = arr[i]-minValue;
            if(mp.find(curIndex)==mp.end())
            {
                mp.insert({curIndex,1});
            }
            else
            {
                mp[curIndex]++;
            }
        }
        map<int,int>::iterator it = mp.begin();
        map<int,int>::iterator nextIt = it;
        nextIt++;
        vector<vector<int>> minRes;
        long curMin = long(INT_MAX)*3;
        for(;nextIt!=mp.end();it++,nextIt++)
        {
            if(it->second>1||nextIt->second>1)
            {
                curMin = 0;
                minRes.push_back({it->first+minValue,nextIt->first+minValue});
            }
            else
            {
                long value =  (long)((nextIt->first)-(it->first));
                if(value<curMin)
                {
                    curMin = value;
                    minRes.clear();
                    minRes.push_back({it->first+minValue,nextIt->first+minValue});
                }
                else if(value==curMin)
                {
                    minRes.push_back({it->first+minValue,nextIt->first+minValue});
                }
            }

        }
        //vector<int> res;
        //while(!minRes.empty())
        //{
        //    pair curP = minRes.front();
        //    res.push_back({curP.first,curP.second});
        //    minRes.pop();
        //}
        return minRes;


    }
};


int main()
{
    Solution so;
    vector<int> test = {4,2,1,3};
    vector<vector<int>> res = so.minimumAbsDifference(test);


    return 0;
}