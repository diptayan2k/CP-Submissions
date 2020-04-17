#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcount(x)
using namespace std;
ll n;
vector<ll> v[200001];
ll subtr[200001];
ll dp[200001];
ll dp1[200001];

ll dfs(ll u, ll par)
{
    subtr[u]=1;
    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs(i,u);
        subtr[u]+=subtr[i];
    }

    dp[u]=subtr[u];


    for(auto i:v[u])
    {
        if(i==par) continue;
        dp[u]+=dp[i];
    }

}

ll dfs1(ll u ,ll par)
{
    dp1[u]=dp[par]-dp[u]+dp1[par]-subtr[u];
    dp1[u]+=n-subtr[u];
    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs1(i,u);
    }

}



void solve(ll t)
{
    cin>>n;
    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1,0);
    dp[0]=dp[1]+subtr[1];
    dfs1(1,0);
    //f(i,1,n) cout<<dp1[i]<<" "<<dp[i]<<endl;
    ll ma=0;
    f(i,1,n) ma=max(ma,dp[i]+dp1[i]);
    cout<<ma<<endl;


}


int main()
{
    ll t=1;
    //scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}
