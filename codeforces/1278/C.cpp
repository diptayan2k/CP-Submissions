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
 vector<ll> a,b;
 ll ov[2]={0},r[2]={0},l[2]={0};
 f(i,0,n-1)
 {
     ll x;
     cin>>x;
     a.pb(x);
 }
 f(i,0,n-1)
 {
     ll x;
     cin>>x;
     b.pb(x);
 }
 reverse(a.begin(),a.end());
 map<ll,ll> m;
 for(auto i: a)
 {
     l[i%2]++;
 }
  for(auto i: b)
 {
     r[i%2]++;
 }

 ll ans=2*n;
 ll p=r[0]-r[1];
 ll q=l[0]-l[1];

 f(i,0,n-1)
 {
     r[b[i]%2]--;
     ll d=r[0]-r[1];
     if(d+q==0) ans=min(ans,i+1);
     if(m[d]==0) m[d]=(i+1);
 }


 if(q+p==0) {cout<<0<<endl; return;}



 f(i,0,n-1)
 {
     l[a[i]%2]--;
     ll d=l[0]-l[1];
     if(d+p==0) ans=min(ans,i+1);
     else if(m[-1*d]!=0) ans=min(ans,i+m[-1*d]+1);

 }
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
