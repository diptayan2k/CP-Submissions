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

void solve()
{
ll n,p,k;
cin>>n>>p>>k;
ll a[n+1];
a[0]=0;
f(i,1,n) cin>>a[i];
sort(a,a+n+1);
ll dp[n+1];
dp[0]=a[0];
f(i,1,n)
{
    if(i<k)
    {
        dp[i]=dp[i-1]+a[i];
    }
    else
    {
        dp[i]=a[i]+dp[i-k];
    }

}
ll ans=0;
f(i,1,n) if(dp[i]<=p) ans=i;

cout<<ans<<endl;

}

int main()
{
   ll t=1;
   cin>>t;

   while(t--)
   {
       solve();
   }

}
