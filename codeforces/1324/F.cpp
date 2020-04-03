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

ll n;
vector<ll> v[200001];
ll a[200001];
ll dp[200001];
ll dp1[200001];

void dfs(ll u, ll par)
{
    dp[u]=a[u];

    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs(i,u);
        dp[u]+=max((ll)0,dp[i]);
    }

}

void dfs1(ll u, ll par)
{

    dp1[u]=max(dp[par]-max(dp[u],(ll)0)+dp1[par],(ll)0);
    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs1(i,u);
    }
}


void solve(ll t)
{
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
        if(a[i]==0) a[i]=-1;
    }

    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1,0);
    dp1[0]=0;

    dfs1(1,0);

    f(i,1,n)
    {
        cout<<dp[i]+dp1[i]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    
    f(i,1,t)
    {
        solve(i);
    }

}

