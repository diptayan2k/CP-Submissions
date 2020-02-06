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
ll n,p;
cin>>n>>p;
ll x=31;
//cout<<x<<endl;
f(i,0,x)
{
    ll c=0;
    ll d=n-i*p;
    if(d<0) break;
    f(j,0,x) if((1<<j)&d) c++;
    //cout<<c<<" "<<d<<endl;
    if(c<=i&&i<=d) {cout<<i<<endl; return;}

}
cout<<-1<<endl;


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t=1;
//cin>>t;

   while(t--)
   {
       solve();
   }

}
