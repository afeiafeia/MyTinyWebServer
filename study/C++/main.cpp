#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int max = 0;
    vector<int> vctRes;
    for(int i=1;i<m;i++)
    {
        int cur = n*i;
        int rev = 0;
        while(cur%10)
        {
            rev = rev*10+cur%10;
            cur/=10;
        }
        if(rev>max)
        {
            max = rev;
        }
    }

    system("pause");
    cout<<max<<endl;
    return 0;
}