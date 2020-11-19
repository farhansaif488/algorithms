#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> edges[101],d,vis,low,parent;
vector<ll> articulation_point,count_ap;

vector<pair<ll,ll>> bridges;

ll t;
ll s; // source may change each time i call find arti point functiobn

void init()
{
    t = 0;

    
    
    count_ap.clear();

    bridges.clear();

    articulation_point.clear();
    articulation_point.assign(101,-1);

    vis.clear();
    vis.assign(101,0);

    low.clear();
    low.assign(101,0);

    d.clear();
    d.assign(101,0);

    parent.clear();
    parent.assign(101,-1);
    
}

void FindArticulationPoint(ll u)
{
    t +=1;
    low[u]=d[u]=t;
    vis[u]=1;
    ll no_of_children = 0;

    for(auto v : edges[u])
    {
        if(v == parent[u]) continue;

        if(vis[v])
        {
            low[u] =  min(low[u],d[v]);
        }

        if(!vis[v])
        {
            parent[u] = v;
            FindArticulationPoint(v);
            low[u] = min(low[u],low[v]);

            if(d[u] <= low[v] && u != 1) //not root find //we are doing it manually,need to find reason
            {
                if(articulation_point[u] != 1)
                count_ap.push_back(u);
            
                articulation_point[u] = 1;
            }
            no_of_children +=1;
        }
        if(no_of_children > 1 && u == 1)
        {
            if(articulation_point[u] !=1)
            count_ap.push_back(u);
            
            articulation_point[u] = 1;
            bridges.push_back({u,v});

        }
    }
}

int main()
{
    cin>>t;
    int cnt = 0;
    while(t--)
    {
        init();
        for(ll i=0;i<=100;i++)
        {
            edges[i].clear();
        }

        ll n;
        cin>>n;
        //Input 
        for(ll i=0;i<n;i++)
        {
            ll p;
            cin>>p;

            ll q;
            cin>>q;

            for(ll j=0;j<q;j++)
            {
                ll u;
                cin>>u;
                edges[p].push_back(u);
            }

        }
        
        for(ll k = 0;k<n;k++)
        {
            if(!vis[k])
            {
                s = k;
                FindArticulationPoint(s);
            }

        }
        cout<<"Test case:::"<<++cnt<<"\n";

        for(auto y : bridges)
        {
            cout<<y.first<<" "<<y.second<<endl;
        }

    }
}