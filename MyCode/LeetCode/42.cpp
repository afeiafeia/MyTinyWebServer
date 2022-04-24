
//接雨水

#include <string>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {

        int size = (int)height.size();
        stack<int> s;
        vector<int> arrL(size,0);
        for(int i=0;i<size;i++)
        {
            while(!s.empty()&&height[s.top()]<=height[i])
            {
                arrL[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        vector<vector<int>> regionL;
        for(int i=0;i<size;i++)
        {
            if(arrL[i]>1)
            {
                regionL.push_back({i,arrL[i]+i});
                i=arrL[i]+i-1;
            }
        }

        stack<int> sR;
        vector<int> arrR(size,0);
        for(int i=size-1;i>=0;i--)
        {
            while(!sR.empty()&&height[sR.top()]<height[i])
            {
                arrR[sR.top()] = sR.top()-i;
                sR.pop();
            }
            sR.push(i);
        }

        vector<vector<int>> regionR;
        for(int i=size-1;i>0;i--)
        {
            if(arrR[i]>1)
            {
                regionR.push_back({i-arrR[i],i});
                i=i-arrR[i]+1;;
            }
        }
        vector<vector<int>> tmpRegionR;
        while(!regionR.empty())
        {
            tmpRegionR.push_back(regionR.back());
            regionR.pop_back();
        }
        regionR = tmpRegionR;

        vector<vector<int>> region;
        MergeTwoRegion(regionL,regionR,region);
        int sum = 0;
        for(int i=0;i<region.size();i++)
        {
            int stIndex = region[i][0];
            int edIndex = region[i][1];
            sum+=((edIndex-stIndex-1)*min(height[stIndex],height[edIndex]));
            for(int j=stIndex+1;j<edIndex;j++)
            {
                sum-=height[j];
            }
        }

        return sum;

    }


    void MergeTwoRegion(vector<vector<int>> &iRegionL,vector<vector<int>> &iRegionR,vector<vector<int>> &oMergeRegion)
    {
        oMergeRegion.clear();
        int sizeL = iRegionL.size();
        int sizeR = iRegionR.size();
        int l=0;
        int r=0;
        while(l<sizeL&&r<sizeR)
        {
            if(iRegionL[l][0]<=iRegionR[r][0])
            {
                oMergeRegion.push_back(iRegionL[l]);
                l++;
            }
            else
            {
                oMergeRegion.push_back(iRegionR[r]);
                r++;
            }
        }
        while(l<sizeL)
        {
             oMergeRegion.push_back(iRegionL[l]);
             l++;
        }
         while(r<sizeR)
        {
             oMergeRegion.push_back(iRegionR[r]);
             r++;
        }

        vector<vector<int>> tmpMergeRegion = oMergeRegion;
        oMergeRegion.clear();
        oMergeRegion.push_back(tmpMergeRegion[0]);
        for(int i=1;i<tmpMergeRegion.size();i++)
        {
            if(oMergeRegion.back()[1]>tmpMergeRegion[i][0])
            {
                oMergeRegion.back()[1]=max(oMergeRegion.back()[1],tmpMergeRegion[i][1]);
            }
            else
            {
                oMergeRegion.push_back(tmpMergeRegion[i]);
            }
        }

    }
};

int main()
{
    Solution so;
    vector<int> test = {4,2,3};
    int res = so.trap(test);


    return 0;
}