#include <string>
using namespace std;
//字符串匹配BM算法
//判断pattern是否为str的子串
bool BM(const string &str,const string &patternStr)
{
    int strSize = str.size();
    int patternSize = patternStr.size();
    int stIndex = 0;
    int edIndex = strSize-patternSize;
    while(stIndex<edIndex)
    {
        int i=patternSize-1;
        for(;i>=0;i--)
        {
            //发现坏字符
            if(str[i+stIndex]!=patternStr[i])
            {
                break;
            }
        }
        if(i<0)
        {
            return true;
        }
        int sameCharIndex = findSameCharIndex(patternStr,str[i],i);
        int offset = sameCharIndex>0?i-sameCharIndex:i+1;
        stIndex+=offset;

    }
    return false;
}

int findSameCharIndex(const string &str,char ch,int edIndex)
{
    for(int i=edIndex;i>=0;i++)
    {
        if(str[i]==ch)
        {
            return i;
        }
    }
    return -1;
}