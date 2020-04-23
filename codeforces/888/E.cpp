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
#define bits(x) __builtin_popcountll(x)
using namespace std;
ll mod=1000000007;
ll n,m;
ll a[40];
set<ll> lef, righ;

void foo(ll idx,ll sum, ll lim)
{
    if(lim==n/2)
    {
        lef.insert(sum%m);
    }
    else
    {
        righ.insert(sum%m);
    }
    if(idx==lim) return;

    foo(idx+1,sum,lim);
    foo(idx+1,sum+a[idx],lim);

}

void solve(ll t)
{
    cin>>n>>m;
    f(i,0,n-1) cin>>a[i];

    foo(0,0,n/2);
    foo(n/2,0,n);

    ll p=lef.size();
    ll q=righ.size();
    ll b[p];
    ll c[q];
    ll pos=0;
    ll ans=0;
    for(auto i: lef)
    {
        b[pos++]=i;
        ans=max(ans,i);
        auto it=righ.end();
        it--;
        ans=max(ans,(i+*it)%m);
    }
    pos=0;
    for(auto i:righ)
    {
        c[pos++]=i;
        ans=max(ans,i);
        auto it=lef.end();
        it--;
        ans=max(ans,(i+*it)%m);
    }

    ll lefpos=0;
    ll righpos=q-1;

    while(lefpos<p and righpos>=0)
    {
        ll comb=b[lefpos]+c[righpos];
        if(comb<m)
        {
            ans=max(comb,ans);
            lefpos++;
        }
        else
        {
            righpos--;
        }
    }
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

