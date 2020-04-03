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
ll ans[200001];

void dfs(ll u, ll par)
{
    ll cnt=0;
    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs(i,u);
        dp[u]=max(dp[u],1+dp[i]);
        cnt++;
    }
    if(cnt==0) dp[u]=1;
}

void dfs1(ll u, ll par)
{

    vector<ll> p;
    for(auto i:v[u])
    {
        if(i==par) continue;
        p.pb(dp[i]);
        dfs1(i,u);
    }
    sort(p.begin(),p.end(),greater<ll>());
    if(p.size()>=2)
        ans[u]=p[0]+p[1];
    else if(p.size()==1) ans[u]=p[0];
}


void solve(ll t)
{
    ll m;
    cin>>n>>m;


    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1,0);
    memset(ans,0,sizeof(ans));
    dfs1(1,0);
    ll ma=0;
    f(i,1,n)
    {
        ma=max(ma,ans[i]);
    }
    cout<<ma;
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

