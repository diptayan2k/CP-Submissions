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
ll dp[200001], ev[200001], od[200001], subtr[200001];
ll dp1[200001], ev1[200001], od1[200001], subtr1[200001];
void dfs(ll u, ll par)
{
    od[u]=0;
    ev[u]=1;
    subtr[u]=1;
    dp[u]=0;
    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs(i,u);
        od[u]+=ev[i];
        ev[u]+=od[i];
        subtr[u]+=subtr[i];
        dp[u]+=(dp[i]+subtr[i]);
    }
}

void dfs1(ll u, ll par)
{
    if(u!=1)
    {
        od1[u]=(ev[par]-od[u])+ev1[par];
        ev1[u]=(od[par]-ev[u])+od1[par];
        dp1[u]=(subtr[par]-subtr[u])+(dp[par]-subtr[u]-dp[u])+dp1[par]+(n-subtr[par]);
    }
    else
    {
        od1[u]=0;
        ev1[u]=0;
        dp1[u]=0;
    }

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
    od[0]=ev[1];
    ev[0]=od[1];
    ev1[0]=0;
    od1[0]=0;
    subtr[0]=n+1;
    dp[0]=dp[1]+subtr[1];
    dfs1(1,0);
    //f(i,1,n) cout<<od[i]+od1[i]<<" "<<ev[i]+ev1[i]<<" "<<dp[i]+dp1[i]<<" "<<dp[i]<<" "<<dp1[i]<<endl;
    ll ans=0;
    ll s=0;
    ll o=0;
    f(i,1,n)
    {
         s+=(dp[i]+dp1[i]);
         o+=(od[i]+od1[i]);
    }

    ans=(s+o)/4;
    cout<<ans<<endl;



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
/*
12
1 2
1 3
2 4
2 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12
*/
