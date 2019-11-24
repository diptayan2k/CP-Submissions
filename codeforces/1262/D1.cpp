#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define ds set <ll, greater<ll> >
using namespace std;

bool sortinrev(const pair<ll,ll> &a,
               const pair<ll,ll> &b)
{
       return (a.first > b.first);
}


int main()
{


ll n;
cin>>n;
ll a[n];

vector< pair<ll,ll> > vvv;
f(i,0,n-1) {
cin>>a[i];
}
f(i,0,n-1)
vvv.pb({-1*a[i],i});
sort(vvv.begin(),vvv.end());



ll t;
cin>>t;

while(t--)
{
    ll k,p;
    cin>>k>>p;
    vector< pair<ll,ll> > v;


    f(i,0,k-1)
    {
        v.pb({vvv[i].S,-1*vvv[i].F});
    }

    sort(v.begin(),v.end());

    cout<<v[p-1].S<<endl;

}

return 0;
}









