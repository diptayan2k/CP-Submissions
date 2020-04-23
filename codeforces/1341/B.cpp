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

bool cmp( pair<ll,ll>  a, pair<ll,ll>  b)
{
    if(a.S==b.S)
    {
        return a.F<b.F;
    }
    return a.S>b.S;
}

void solve(ll t)
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll b[n]={0};
    f(i,0,n-1) cin>>a[i];

    ll num=0;

    f(i,1,n-2)
    {
        if(a[i]>a[i-1] and a[i]>a[i+1])
        {
            if(i<k-1) num++;
            b[i]=1;
        }
    }

    vector< pair<ll,ll> > v;
    ll p=0;
    ll q=k-1;

    while(q<n)
    {
        v.pb({p,num});
        if(b[p+1]==1)
        {
            num--;
        }
        if(b[q]==1)
        {
            num++;
        }
        p++;
        q++;

    }
    pair<ll,ll> pp[v.size()];
    ll pos=0;
    for(auto i:v)
    {
        pp[pos++]=i;
        //cout<<i.F<<" "<<i.S<<endl;
    }


    sort(pp,pp+pos,cmp);
    cout<<pp[0].S+1<<" "<<pp[0].F+1<<endl;





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

