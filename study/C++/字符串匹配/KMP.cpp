#include <string>
#include <vector>
using namespace std;
int KMP(const string &str,const string &patternStr)
{
    vector<int> vctNext;
    CreateNext(patternStr,vctNext);
    int strSize = str.size();
    int patternSize = patternStr.size();
    int j=0;
    for(int i=0;i<strSize;i++)
    {
        while(j>0&&str[i]!=patternStr[j])
        {
            j = vctNext[j];
        }
        if(str[i]==patternStr[j])
        {
            j++;
        }
        if(j==patternSize)
        {
            return i-patternSize+1;
        }
    }
    return -1;
}


void CreateNext(const string &iStr,vector<int> &ovctNext)
{
    ovctNext.clear();
    int size = iStr.size();
    if(size<2)
    return ;
    ovctNext.resize(size);
    ovctNext[0]=0;
    ovctNext[1]=0;
    int j=0;
    for(int i=2;i<size;i++)
    {
        while(j>0&iStr[j]!=iStr[i-1])
        {
            j = ovctNext[j];
        }
        if(iStr[j]==iStr[i-1])
        {
            j++;
        }
        ovctNext[i]=j;
    }
}