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

ll mod=1000000007;

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % mod;
    p = (p%mod * p%mod) % mod;

    return (y%2 == 0)? p%mod : (x%mod * p%mod) % mod;
}

void solve()
{
     ll n;
     cin>>n;
     ll a[n];
     f(i,0,n-1) cin>>a[i];
     vector<ll> v;
     f(i,1,n-1) if(a[i-1]==-1&&a[i]!=-1) v.pb(a[i]);
     f(i,0,n-2) if(a[i]!=-1&&a[i+1]==-1) v.pb(a[i]);
     sort(v.begin(),v.end());
     ll b=0,c=0;
     if(!v.empty())
     {c=v[0];
     b=v[v.size()-1];}
     ll p=c+b;
     p/=2;
     f(i,0,n-1) if(a[i]==-1) a[i]=p;
     ll ma=0;
     f(i,0,n-2) ma=max(abs(a[i]-a[i+1]),ma);
     ll q=p+1;
     ll ma1=0;
     f(i,0,n-1) if(a[i]==-1) a[i]=q;
     f(i,0,n-2) ma1=max(abs(a[i]-a[i+1]),ma1);

     if(ma1<ma)
     {
         cout<<ma1<<" "<<q<<endl;
     }
     else{
        cout<<ma<<" "<<p<<endl;
     }



}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
while(t--)
{
   solve();
}


}
