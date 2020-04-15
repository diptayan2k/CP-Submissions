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



ll bs(ll x, ll a[], ll n)
{
    ll lo=0;
    ll hi=n-1;
    ll mid;
    ll ans=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]<=x)
        {
            ans=a[mid];
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
        //cout<<mid<<endl;
    }

    return ans;
}

ll bs1(ll x, ll a[], ll n)
{
    ll lo=0;
    ll hi=n-1;
    ll mid;
    ll ans=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]<x)
        {
            lo=mid+1;
        }
        else
        {
            ans=a[mid];
            hi=mid-1;
        }
    }

    return ans;
}

ll calval(ll a,ll b,ll c)
{
    return ((a-b)*(a-b))+((c-b)*(c-b))+((a-c)*(a-c));
}


void solve(ll t)
{
    ll nr,ng,nb;
    cin>>nr>>ng>>nb;
    ll p[nr],q[ng],r[nb];

    f(i,0,nr-1) cin>>p[i];
    f(i,0,ng-1) cin>>q[i];
    f(i,0,nb-1) cin>>r[i];

    sort(p,p+nr);
    sort(q,q+ng);
    sort(r,r+nb);


    //cout<<bs((ll)10,p,nr)<<endl;


    ll ans=calval(p[0],q[0],r[0]);

    f(i,0,nr-1)
    {
        ll a=p[i];
        ll b=bs(a,q,ng);
        ll c=bs1(a,q,ng);
        ll d=bs(a,r,nb);
        ll e=bs1(a,r,nb);
        ll lol1 , lol2;
        if(b==-1)
        {
            b=c;
        }
        else if(c==-1)
        {
            c=b;
        }

        if(d==-1)
        {
            d=e;
        }
        else if(e==-1)
        {
            e=d;
        }

        ll lolwa=min(min(calval(a,b,d),calval(a,b,e)),min(calval(a,c,d),calval(a,c,e)));
        ans=min(ans,lolwa);

    }

    f(i,0,ng-1)
    {
        ll a=q[i];
        ll b=bs(a,p,nr);
        ll c=bs1(a,p,nr);
        ll d=bs(a,r,nb);
        ll e=bs1(a,r,nb);

        if(b==-1)
        {
            b=c;
        }
        else if(c==-1)
        {
            c=b;
        }

        if(d==-1)
        {
            d=e;
        }
        else if(e==-1)
        {
            e=d;
        }

        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;

        ll lolwa=min(min(calval(a,b,d),calval(a,b,e)),min(calval(a,c,d),calval(a,c,e)));
        ans=min(ans,lolwa);

    }
    f(i,0,nb-1)
    {
        ll a=r[i];
        ll b=bs(a,q,ng);
        ll c=bs1(a,q,ng);
        ll d=bs(a,p,nr);
        ll e=bs1(a,p,nr);

        if(b==-1)
        {
            b=c;
        }
        else if(c==-1)
        {
            c=b;
        }

        if(d==-1)
        {
            d=e;
        }
        else if(e==-1)
        {
            e=d;
        }

        ll lolwa=min(min(calval(a,b,d),calval(a,b,e)),min(calval(a,c,d),calval(a,c,e)));
        ans=min(ans,lolwa);

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
