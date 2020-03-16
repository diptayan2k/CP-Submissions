#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizof(arr))
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll neginf=-100000000000000000;
ll n;
ll dp[1000001];
ll dp1[1000001];
vector<ll> v[1000001];
ll a[1000001];
ll mx1[1000001];
ll mx2[1000001];
bool vis[1000001];
bool vis1[1000001];
ll cn=0;
void dfs(ll u)
{
    vis[u]=true;
    dp[u]=a[u];
    dp1[u]=neginf;

    for(auto i: v[u])
    {
        if(!vis[i])
        {
            dfs(i);
            dp[u]+=dp[i];
            dp1[u]=max(dp1[u],dp1[i]);
        }

    }
    dp1[u]=max(dp1[u],dp[u]);


}


void bfs2()
{
    queue<ll> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        mx1[u]=neginf;
        mx2[u]=neginf;
        vector<ll> p;

        for( auto i: v[u])
        {


            if(!vis[i])
            {
                p.pb(dp1[i]);
            }
        }
        if(p.size()>=2)
        {
            sort(p.begin(),p.end(),greater<ll>());
            mx1[u]=p[0];
            mx2[u]=p[1];

        }

        for( auto i: v[u])
        {
            if(!vis[i])
                q.push(i),vis[u]=true;

        }
    }

}


void solve(ll t)
{
    cin>>n;
    f(i,1,n) cin>>a[i];
    f(i,2,n)
    {
        ll x,y;
        cin>>x>>y;
        v[y].pb(x);
        v[x].pb(y);

    }
    memset(vis,false,sizeof(vis));
    memset(dp,0,sizeof(dp));
    dfs(1);
    memset(vis,false,sizeof(vis));
    bfs2();
    ll ans=neginf;
    for(ll i=1;i<=n;i++)
    {

        if(mx1[i]!=neginf and mx2[i]!=neginf) ans=max(ans,mx1[i]+mx2[i]);
    }
    if(ans==neginf) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;







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
