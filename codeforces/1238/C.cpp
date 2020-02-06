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

 ll h,n;
 cin>>h>>n;
 ll a[n+1];
 f(i,0,n-1) cin>>a[i];
 a[n]=-5;
 vector<ll> v;
 ll l=1;
 f(i,1,n)
 {
     if(a[i]==a[i-1]-1) l++;
     else
     {
         v.pb(l);
         l=1;

     }
 }
 if(a[n-1]==1) if(!v.empty()) v.pop_back();
 //for(auto i: v) cout<<i<<" ";
 //cout<<endl;
 if(v.empty())
 {
     cout<<0<<endl;
     return;
 }

 ll c=0;
 f(i,0,v.size()-1) v[i]%=2;
 f(i,0,v.size()-1)
 {
     if(i==0&&v[i]==0) c++;
     else if(i>0&&v[i]==1) c++;
 }
 cout<<c<<endl;

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t=1;
cin>>t;

   while(t--)
   {
       solve();
   }

}
