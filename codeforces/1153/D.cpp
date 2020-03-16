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

ll n;
ll dp[1000001];
vector<ll> v[1000001];
ll a[1000001];
bool vis[1000001];
ll cn=0;
void dfs(ll u)
{
    vis[u]=true;
    if(v[u].size()==1 and u!=1) { cn++; dp[u]=1; return;}

    ll p=0;
    ll q=1000000000;
    for(auto i: v[u])
    {
        if(!vis[i])
        {
            dfs(i);
            p+=dp[i];
            q=min(q,dp[i]);
        }

    }
    if(a[u]==0)
        dp[u]=p;
    else
        dp[u]=q;

}


void solve(ll t)
{
    cin>>n;
    f(i,1,n) cin>>a[i];
    f(i,2,n)
    {
        ll x;
        cin>>x;
        v[i].pb(x);
        v[x].pb(i);

    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    //for(ll i=1;i<=n;i++) cout<<dp[i]<<" ";
    //cout<<endl;
    cout<<cn-dp[1]+1;





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
