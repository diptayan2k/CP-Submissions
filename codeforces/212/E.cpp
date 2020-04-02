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
vector<ll> v[5010];
set<pair<ll,ll> > s;
ll dp[5010][5010];
ll a[5010],p[5010];

void foo(ll idx, ll sum, ll k)
{

    if(idx==k) return;
    if(dp[idx][sum]==1) return;
    if(sum>0 and abs((n-1)-sum)>0)
    {
        s.insert({sum,n-1-sum});
        s.insert({n-1-sum,sum});
    }

        foo(idx+1,sum+p[idx],k);
        foo(idx+1,sum,k);

        dp[idx][sum]=1;

}

void dfs(ll u, ll par)
{
    a[u]=1;

    ll cnt=0;
    for(auto i: v[u])
    {
        if(i==par) continue;
        dfs(i,u);
        cnt++;
        a[u]+=a[i];
    }
    //cout<<u<<" "<<a[u]<<endl;
    ll k=0;
    for(auto i:v[u])
    {
        if(i!=par)
            p[k++]=a[i];
    }
    if(k==0) return;
    if(a[u]!=n)
        p[k++]=(n-a[u]);

    if(k>=2)
    {

        f(i,0,k) f(j,0,n) dp[i][j]=-1;
        foo(0,0,k);
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
    cout<<s.size()<<endl;
    for(auto i:s)
    {
        cout<<i.F<<" "<<i.S<<endl;
    }




}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    //cin>>t;

    f(i,1,t)
    {
        solve(i);
    }

}

