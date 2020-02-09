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

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;

cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll b[n];
ll p=0;
f(i,0,n-1)
{
    b[i]=p;
    //cout<<b[i]<<" ";
    p=(p|a[i]);
}
ll c[n];
p=0;
g(i,n-1,0)
{
    c[i]=p;
    p=(p|a[i]);
}

pair<ll,ll> an[n];
f(i,0,n-1)
{
    //cout<<b[i]c[i]<<endl;
    an[i].F=(b[i]|c[i]);
    an[i].S=a[i];
}
sort(an,an+n);
for(auto i:an)
    cout<<i.S<<" ";

}
