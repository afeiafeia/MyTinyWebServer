#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        int edgeNum = (int)edges.size();
        vector<vector<int>> vctGraph(n);
        //cout<<edgeNum<<endl;

        for(int i=0;i<edgeNum;i++)
        {
            vctGraph[edges[i][0]].push_back(edges[i][1]);
            vctGraph[edges[i][1]].push_back(edges[i][0]);
        }

        int minPath = 1<<31;
        vector<int> res;
        vector<int> vctPath;
        for(int i=0;i<n;i++)
        {
            int curMin = 0;
            vector<bool> choosed(n,false);
            queue<int> q;
            q.push(i);
            choosed[i] = true;
            int curLevel = 1;
            int nextLevel = 0;
            while(!q.empty())
            {
                int curIndex = q.front();
                //q.pop();
                int levelNum = vctGraph[curIndex].size();
                for(int j=0;j<=curLevel&&!q.empty();j++)
                {
                    curIndex = q.front();
                    q.pop();
                    for(auto& it:vctGraph[curIndex])
                    {
                        if(!choosed[it])
                        {
                            nextLevel++;
                            q.push(it);
                        }
                        choosed[it]=true;
                    }
                }
                curLevel=nextLevel;
                //if(curLevel==0)
                {
                    curMin++;
                    if(curMin>minPath)
                    {
                        curMin = 1<<31;
                        break;
                    }
                }
                curLevel = nextLevel;
            }
            if(curMin<minPath)
            {
                minPath =curMin;
            }
            vctPath[i] = curMin;

        }

        for(int i=0;i<n;i++)
        {
            if(vctPath[i]==minPath)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};


int main()
{
    Solution so;
    vector<vector<int>> test = {{1,0},{1,2},{1,3}};
    so.findMinHeightTrees(4,test);


    return 0;
}