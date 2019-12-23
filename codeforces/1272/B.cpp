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
cin>>t;
while(t--)
{
 string s;
 cin>>s;
 map<char,ll> m;
 f(i,0,s.length()-1)
 {
    m[s[i]]++;
 }
 //cout<<m['L']<<" "<<
 ll ans = 2*min(m['L'],m['R'])+2*min(m['U'],m['D']);

 ll a,b;
 a= min(m['L'],m['R']);
 b= min(m['U'],m['D']);;

 if(a==0&&b>0)
 {
     cout<<2<<endl<<"UD"<<endl;
     continue;
 }
 if(a>0&&b==0)
 {
     cout<<2<<endl<<"LR"<<endl;
     continue;
 }

 cout<<ans<<endl;
 f(i,1,min(m['L'],m['R']))
 {
     cout<<"L";
 }
 f(i,1,min(m['U'],m['D']))
 {
     cout<<"U";
 }
 f(i,1,min(m['L'],m['R']))
 {
     cout<<"R";
 }
 f(i,1,min(m['U'],m['D']))
 {
     cout<<"D";
 }
 cout<<endl;

}

return 0;
}







