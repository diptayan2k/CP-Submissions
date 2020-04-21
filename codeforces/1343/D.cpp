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
ll mod=1000000007;


ll bs(ll n,ll b[],ll x)
{
    ll lo=0;
    ll hi=n-1;
    ll mid;
    ll ans=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(b[mid]<x)
        {
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return ans+1;
}


ll bs1(ll n,ll b[],ll x)
{
    ll lo=0;
    ll hi=n-1;
    ll mid;
    ll ans=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(b[mid]>x)
        {
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return ans+1;
}

void solve(ll t)
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(i,0,n-1)
         cin>>a[i];

    ll b[n/2];
    ll c[n/2];
    map<ll,ll> mp;
    f(i,0,n/2-1)
    {
        b[i]=max(a[i],a[n-i-1])+k;
        c[i]=min(a[i],a[n-i-1])+1;
        mp[a[i]+a[n-i-1]]++;
    }
    ll m=n/2;
    sort(b,b+m);
    sort(c,c+m,greater<ll>());

    ll ans=mod;
    f(i,2,2*k)
    {
        ll p=bs(m,b,i);
        ll q=mp[i];
        ll r=bs1(m,c,i);
        ans=min(ans,2*p+2*r+(m-(p+q+r)));
        //cout<<p<<" "<<q<<endl;
    }
    cout<<ans<<endl;






}


int main()
{
    ll t=1;
    scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}

