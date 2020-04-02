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

struct str
{
    ll x,y,t;
    long double p;
} st[1002];

bool comp(str a, str b)
{
    return a.t<b.t;
}
long double dp[1002][1002];

long double foo(ll idx,ll prev)
{

    if(idx==n+1)
    {
        return 0;
    }

    if(dp[idx][prev]!=-1) return dp[idx][prev];

    long double res=foo(idx+1,prev);
    if(sqrt(abs(st[prev].x-st[idx].x)*abs(st[prev].x-st[idx].x)+abs(st[prev].y-st[idx].y)*abs(st[prev].y-st[idx].y))<=abs(st[idx].t-st[prev].t))
    {
        res=max(res,st[idx].p+foo(idx+1,idx));
        //cout<<idx<<endl;
    }

    return dp[idx][prev]=res;

}

void solve(ll t)
{
    cin>>n;

    f(i,1,n)
    {
        cin>>st[i].x>>st[i].y>>st[i].t>>st[i].p;
    }
    st[0].x=0;
    st[0].y=0;
    st[0].t=10000000000000007;
    st[0].p=0;

    f(i,0,1001) f(j,0,1001) dp[i][j]=-1;


    sort(st+1,st+n+1,comp);



    /*
    f(i,0,n)
    {
        cout<<st[i].x<<" "<<st[i].y<<" "<<st[i].t<<" "<<st[i].p<<endl;
    }*/

    cout<<fixed<<setprecision(10)<<foo(1,0);


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

