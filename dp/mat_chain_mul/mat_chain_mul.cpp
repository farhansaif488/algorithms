#include <bits/stdc++.h>
using namespace std;


#define MAX_N   100
#define INF     10000
#define EMPTY_VALUE -1


int n=0,t=0;

int mem[MAX_N][MAX_N];

struct Matrix{
    int row,col;

    
    Matrix(int _row,int _col)
    {
        row = _row;
        col = _col;
    }
};

vector<Matrix> mats;

int mergeCost(int i,int j,int k)
{
    return (mats[i].row)*(mats[k].col)*(mats[j].col);
}

int f(int i,int j)
{
    //memset(mem,-1,sizeof(mem));
    if(i >= j)
    {
        return 0;
    }
    if(mem[i][j] != EMPTY_VALUE)
    { 
        return mem[i][j];
    }
    int ans = INF;

    for(int k = i;k<j;k++)
    {
        int res_left =  f(i,k);
        int res_right = f(k+1,j);

        int cost = (res_left+res_right)+mergeCost(i,j,k);
        ans = min(ans,cost);
    }

    mem[i][j] = ans;
    return mem[i][j];

}


int main()
{
    cin>>t;
    int h = t+1;
    while(t--)
    {
        memset(mem,-1,sizeof(mem));
        mats.clear();
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int r,c;
            cin>>r>>c;
            mats.push_back({r,c});
        }
        int ans = f(0,n-1);
        cout<<"Count #"<<h-t<<": "<<ans<<endl;

    }   
}