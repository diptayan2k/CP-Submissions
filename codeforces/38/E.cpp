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
ll mod=1000000007;
ll n;
map<ll,ll> m;
pair<ll,ll> p[3001];
ll dp[3001][3001];
ll foo(ll ix, ll next)
{
    if(ix==n)
    {
        return 0;
    }

    if(dp[ix][next]!=-1) return dp[ix][next];

    ll res=mod;

    res=min((foo(ix+1,next)+abs(p[next].F-p[ix].F)),(foo(ix+1,ix)+p[ix].S));


    return dp[ix][next]=res;


}

void solve(ll t)
{
    cin>>n;
    f(i,0,n-1)
    {
        cin>>p[i].F>>p[i].S;
    }

    sort(p,p+n);

    f(i,0,3000) f(j,0,3000) dp[i][j]=-1;

    cout<<foo(1,0)+p[0].S;




}


int main()
{
    ios::sync_with_stdio(0);
    ll t=1;
    //cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}


