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

void solve(ll t)
{

    ll n;
    cin>>n;
    ll a[n+1]={0};
    ll sum=0;
    ll pre[n+1]={0},suf[n+1]={0};
    f(i,0,n-1)
    {
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    g(i,n-1,0)
    {
        suf[i]=suf[i+1]+a[i];
        //cout<<suf[i]<<endl;
    }
    ll dppre[n+1]={0};
    f(i,1,n)
    {
        dppre[i]=max(dppre[i-1]+a[i-1],abs(pre[i]));
    }

    ll dpsuf[n+1]={0};
    g(i,n-1,0)
    {
        dpsuf[i]=max(dpsuf[i+1]+a[i],abs(suf[i]));

    }
    ll ans=-1*mod;
    f(i,0,n) ans=max(ans,dpsuf[i]+dppre[i]);
    cout<<ans<<endl;
}








int main()
{
    ios::sync_with_stdio(0);
    ll t=1;
    f(i,1,t)
    {
        solve(i);
    }

}


