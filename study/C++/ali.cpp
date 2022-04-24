#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetCount(const string &s,string month)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==':')
        {
            month = s.substr(0,i);
            string cur = s.substr(i+1);
            return atoi(cur.c_str());
        }
    }
}
void GetItem(const string &s,double &res)
{
    res= 0.0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==':')
        {
            int stIndex = i+1;
            bool negative = false;
            if(i<s.size()-1&&(s[i+1]=='+'||s[i+1]=='-'))
            {
                stIndex++;
            }
            if(i<s.size()-1&&s[i+1]=='-')
            {
                negative = true;
            }
            while(i<s.size()&&s[i]!=' ')
            {
                i++;
            }
            int len = i-stIndex;
            string cur = s.substr(stIndex,len);
            if(negative)
            {
                res -=atof(cur.c_str());
            }
            else
            {
                res+=atof(cur.c_str());
            }
        }
    }
}
int main()
{
    int n = 24;
    while(n--)
    {
        string s;
        cin>>s;
        string curMonth;
        int count = GetCount(s,curMonth);
        string item;
        cin>>item;
        double curRes = 0.0;
        GetItem(item,curRes);
        char buff[8];
        if(curRes>=0.0)
        {
            buff[0] = '+';
        }
        else if(curRes<0.0)
        {
            buff[0] = '-';
        }
        sprintf(buff+1,".2%d",curRes);
        string sum(buff);
        cout<<curMonth<<":"<<sum<<endl;
    }

    system("pause");
    return 0;
}
