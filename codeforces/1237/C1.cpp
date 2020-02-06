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
 ll n;
 cin>>n;
 ll x[n],y[n],z[n];
 f(i,0,n-1) cin>>x[i]>>y[i]>>z[i];
 //cout<<"HI";
 vector< pair<ll, pair<ll,ll> > > v;
 f(i,0,n-1)
 {
     f(j,i+1,n-1)
     {
         ll p=x[i]-x[j];
         ll q=y[i]-y[j];
         ll r=z[i]-z[j];
         ll dist=p*p+q*q+r*r;
         v.pb({dist,{i+1,j+1}});
     }
 }
 sort(v.begin(),v.end());
 map<ll,ll> m;
 for(auto i: v)
 {
     if(m[i.S.F]==0&&m[i.S.S]==0)
     {
         cout<<i.S.F<<" "<<i.S.S<<endl;
         m[i.S.F]=1;
         m[i.S.S]=1;
     }

 }


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t=1;


   while(t--)
   {
       solve();
   }

}
