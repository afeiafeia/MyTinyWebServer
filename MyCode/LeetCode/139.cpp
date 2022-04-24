#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> hashSet;
        int size = wordDict.size();
        for(int i=0;i<size;i++)
        {
            hashSet.insert(wordDict[i]);
        }
        int end = s.size();
        int stIndex = 0;
        bool res = help(s,0,end,hashSet);
        return res;
        //return false;
    }


    bool help(string &s,int stIndex,int edIndex,unordered_set<string> &hashSet)
    {
        if(stIndex>=edIndex)
        {
            return false;
        }
        bool res = false;
        while(stIndex<edIndex)
        {
            string tmp(&s[stIndex],&s[edIndex]);
            if(hashSet.find(tmp)!=hashSet.end())
            {
                if(edIndex==s.size())
                {
                    return true;
                }
                else
                {
                    res = help(s,edIndex,s.size(),hashSet);
                    if(res)
                    {
                        return true;
                    }
                    edIndex--;
                }
            }
            else
            {
                edIndex--;
            }
        }
        return false;
    }
};

int main()
{
    Solution so;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> vctS = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    so.wordBreak(s,vctS);

    return 0;
}