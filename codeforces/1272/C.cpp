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
#define set set <ll, greater<ll> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;




int main()
{

ll t;
t=1;
while(t--)
{
 ll n,k;
 cin>>n>>k;
 string s;
 cin>>s;
 s+="?";
 map<char,ll> m;
 char ch;
 f(i,0,k-1)
 {
     cin>>ch;
     m[ch]++;
 }
 ll ans=0;
 ll len=0;
 f(i,0,n)
 {
     if(!m[s[i]])
     {
         ans+=len*(len+1)/2;
         len=0;
     }
     else
     {
         len++;
     }
 }
 cout<<ans<<endl;

}

return 0;
}







