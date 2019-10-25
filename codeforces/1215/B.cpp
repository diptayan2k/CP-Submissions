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
using namespace std;
ll mod=1000000007;



int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll pos[n], neg[n];
pos[0]=1; neg[0]=0;
if(a[0]<0) swap(pos[0],neg[0]);
f(i,1,n-1)
{
    if(a[i]<0)
    {
        pos[i]=neg[i-1];
        neg[i]=pos[i-1]+1;
    }
    else
    {
        pos[i]=pos[i-1]+1;
        neg[i]=neg[i-1];
    }
}
ll ans1=0, ans2=0;
f(i,0,n-1)
{
    ans1+=pos[i];
    ans2+=neg[i];
}
cout<<ans2<<" "<<ans1;
}
