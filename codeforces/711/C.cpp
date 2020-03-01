#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
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

ll mod=1000000000000000+7;
ll p[105][105];
ll dp[105][105][105];
ll n,m,k;
ll a[105];
ll foo(ll i, ll bt, ll prev)
{
    if(i==n+1)
    {
        if(bt==k+1) return 0;
        return mod;

    }

    if(dp[i][bt][prev]!=-1) return dp[i][bt][prev];
    ll res=mod;

    if(a[i]!=0)
    {
        res=min(res,foo(i+1,bt+(prev!=a[i]),a[i]));
    }
    else
    {
        f(j,1,m)
        {
            res=min(res,p[i][j]+foo(i+1,bt+(prev!=j),j));
        }
    }

    return dp[i][bt][prev]=res;

}


void solve(ll d)
{

    cin>>n>>m>>k;
    f(i,1,n) cin>>a[i];

    f(i,1,n)
    {
        f(j,1,m) cin>>p[i][j];
    }

    f(i,0,104) f(j,0,104) f(k,0,104) dp[i][j][k]=-1;

    ll ans=foo(1,1,-1);
    if(ans>=mod)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
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



