#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
vector<ll> cycle[101];
ll p;

ll bigmod(ll a,ll b,ll M)
{
    if(b==0)return 1%M;

    ll x = bigmod(a,b/2,M);

    x = (x*x)%M;

    if(b%2==1) x = (x*a)%M;

    return x;
}

ll fib(ll n)
{
    
    if(n<=1)
    {
        return n;
    }

    if(v[n]!=-1)
    {
        return v[n];
    }

    return v[n]=(fib(n-1)+fib(n-2))%p;

}

int main()
{

    v.clear();
    v.assign(1002,-1);
    //cout<<v[0];
    
    for(ll i=0;i<=1002;i++)
    {
        cycle[i].clear();
        cycle[i].assign(1002,-1);
    }
    p=1000;
    ll x = (fib(1000))%p;
    
    v[1]=1;
    v[0]=0;
    cout<<endl;

    
        for(ll j=0;j<=1000;j++)
        cycle[6][j]=v[j];
    

    for(ll i=0;i<=1000;i++)
    {
        cout<<cycle[6][i]<<" ";
    }
    

    cout<<endl;
}