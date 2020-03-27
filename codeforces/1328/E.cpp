#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcount(x)
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ll> v[200001];
ll parent[200001], lev[200001],tout[200001],tin[200001], T=0;

void dfs(ll u, ll par)
{
    parent[u]=par;
    lev[u]=lev[par]+1;
    tin[u]=T++;

    for(auto i: v[u])
    {
        if(i==par) continue;
        dfs(i,u);
    }
    tout[u]=T++;
}

void solve(ll t)
{
    ll n,m;
    cin>>n>>m;
    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    lev[0]=-1;
    dfs(1,0);
    //f(i,1,n) cout<<lev[i]<<" ";
    //cout<<endl;

    while(m--)
    {
        ll k;
        cin>>k;
        ll a[k];
        ll p=0,q=1;
        f(i,0,k-1)
        {
            cin>>a[i];
        }
        f(i,0,k-1)
        {
            if(a[i]!=1)
                a[i]=parent[a[i]];
            //cout<<a[i]<<" ";
            //cout<<endl;
            if(lev[a[i]]>p)
            {
                p=lev[a[i]];
                q=a[i];
            }
        }
        ll s=0;
        //cout<<p<<" "<<q<<endl;
        for(auto i:a)
        {
            if(tout[q]<=tout[i] and tin[q]>=tin[i]) s++;
        }
        if(s==k)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }




}

int main()
{
    ll t=1;
    //cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}






