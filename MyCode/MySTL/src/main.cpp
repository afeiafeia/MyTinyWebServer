#include<iostream>
#include<vector>
using namespace std;





int MaxLike(vector<int>& ivctMoneySum,vector<vector<int>>& ivctLikeability)
{
    int likeSize = (int)ivctLikeability.size();
    vector<double> vctUnitLike(likeSize,0.0);
    vector<int> vctIndex(likeSize,0);
    for(int i=0;i<ivctLikeability.size();i++)
    {
        double price = (double)ivctLikeability[i][0];
        vctUnitLike[i] = ivctLikeability[i][2]/price;
        vctIndex[i] = i;
    }


    for(int j=0;j<likeSize;j++)
    {
        for(int k=likeSize-1;k>j;k--)
        {
            if(vctUnitLike[k]<vctUnitLike[k-1])
            {
                double tmp = vctUnitLike[k];
                vctUnitLike[k] = vctUnitLike[k-1];
                vctUnitLike[k-1]=tmp;
                
                int tmpIndex = vctIndex[k];
                vctIndex[k] = vctIndex[k-1];
                vctIndex[k-1]=tmpIndex;

            }
        }
    }

    int max = 0;
    int sumMoney = ivctMoneySum[0];

    for(int i=likeSize-1;i>=0&&sumMoney;i--)
    {
        int index = vctIndex[i];
        int price = ivctLikeability[index][0];

        int buyCount = sumMoney/price;
        if(buyCount<1)
        continue;
        else
        {
            //只买一个
            max+=ivctLikeability[index][2];
            sumMoney -=ivctLikeability[index][0];
        }

    }

    return max;
}





int Testmain()
{

    vector<int> vctMoney(2,0);
    vctMoney[0]=6;
    vctMoney[1]=7;

    vector<vector<int>> vctLike = {
        {3,1,8},
        {4,1,2},
        {3,1,1},
        {9,1,7},
        {4,1,1},
        {5,1,18},
        {4,1,4}
        };

        int max = MaxLike(vctMoney,vctLike);

        
        cout<<max<<endl;
        system("pause");
        return 0;
}


vector<int> direction{-1,0,1,0,-1};


int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vctVisit,int r,int c,vector<int> src,vector<int> destination,int min)
{
    if(vctVisit[r][c]<min)
    return -1;


    min++;
    if(r==destination[0]&&c==destination[1])
    {return min;}
    else if(grid[r][c])
    {return -1;}
    
    vctVisit[r][c]=true;

    int x=0;
    int y=0;
    int minPath = -1;
    int oriMin = min;
    for(int i=0;i<4;i++)
    {
        x=r+direction[i];
        y=c+direction[i+1];

        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size())
        {
            //vctVisit[x][y]=true;
            int curmin = dfs(grid,vctVisit,x,y,src,destination,min);
            if(curmin<0)
            {
                continue;
            }
            else
            {
                if(minPath<0)
                {
                    minPath = curmin;
                }
                else
                {
                    minPath = minPath<curmin?minPath:curmin;
                }
            }
            //vctVisit[x][y]=false;

        }
    }

    vctVisit[r][c]=false;

    return minPath;
}


//int MinPathNumMain(vector<vector<int>>& grid)
int mainOld()
{
    vector<int> MN = {3,5};
    vector<vector<int>> grid=
    {
        {1,0,2,0,3},
        {0,2,0,1,1},
        {0,3,0,0,0},
    };

    //vector<int> MN = {2,3};
    //vector<vector<int>> grid=
    //{
        //{1,0,2},
        //{0,2,0}
    //};

    vector<vector<bool>> vctVisit(MN[0],vector<bool>(MN[1],false));

    vector<vector<int>> vctPnts = {{0,0},{2,4}};


    if(grid.empty()||grid[0].empty())
    return 0;

    int minPathNum = -1;

    int x;
    int y;

    vctVisit[vctPnts[0][0]][vctPnts[0][1]]=true;
    for(int i=0;i<4;i++)
    {
        x=vctPnts[0][0]+direction[i];
        y=vctPnts[0][1]+direction[i+1];


        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size())
        {
            
            int curmin = dfs(grid,vctVisit,x,y,vctPnts[0],vctPnts[1],0);
            if(curmin<0)
            {
                continue;
            }
            else
            {
                if(minPathNum<0)
                {
                    minPathNum = curmin;
                }
                else
                {
                    minPathNum = minPathNum<curmin?minPathNum:curmin;
                }
            }
            

        }
    }

    
    cout<<minPathNum<<endl;
    system("pause");

    return 0;


}




    int getMaxMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<int> b(M,0);
        int sum;
        int maxsum=-1e20;

        for(int i=0;i<N;i++){     
            for(int t=0;t<M;t++ ) b[t]=0;    
            for(int j=i;j<N;j++){    
                sum = 0;
                for(int k=0;k<M;k++){
                    b[k]+=matrix[j][k];   

                    if(sum>0){
                        sum+=b[k];
                    }
                    else{
                        sum=b[k];
                      
                    }
                    if( sum > maxsum){
                        maxsum = sum;
  
                    }
                }
            }
        }

        return maxsum;
    }


int main()
{
    int m=0;
    int n=0;
    std::string size;
    getline(std::cin,size);
    std::vector<int> mn;
    for(int i=0;i<size.size();i++)
    {
        if(size[i]!=' ')
        {
            int k=i;
            int num = 0;
            for(int l=k;l<10;l++)
            {
                if(size[l]!=' ')
                num+=int((size[l]-'0'))*10;
                else
                {
                    i=l;
                }
                break;
            }
            num /=10;
            mn.push_back(num);
            if(mn.size()==2)
            break;
        }
    }
    n = mn[0];
    m  =mn[1];

    vector<vector<int>> matrix(n,vector<int>(m,0)); 

    for(int i=0;i<n;i++)
    {
        string buff;
        getline(std::cin,buff);
        vector<int> curInput;
        for(int k=0;k<buff.size();k++)
        {
            if(buff[k]!=' ')
            {
                bool neg = false;
                if(buff[k]=='-')
                {
                    neg = true;
                    k++;
                }
                char tmp[32];
                int sum = 0;
                for(int l=k;l<buff.size();l++)
                {
                    if(buff[l]!=' ')
                    sum+=int((buff[l]-'0'))*10;
                    else
                    {
                        k = l;
                        break;
                    }
                }
                
                sum/=10;
                if(neg)
                {
                    sum = 0-sum;
                }
                curInput.push_back(sum);
            }

        }
        matrix[i] = curInput;

    }  
    int sum =0;
    sum = getMaxMatrix(matrix);
    std::cout<<sum<<std::endl;
     system("pause");
     return 0;
}