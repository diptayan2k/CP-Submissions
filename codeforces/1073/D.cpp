#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define ff long double
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define w while
#define F first
#define vv vector
#define S second
#define mp make_pair
using namespace std;

int main()
{ ll n,t;
cin>>n>>t;
ll a[n];
ll d[n+1];
ll b[n];
d[0]=0;
ll m=1000000000000;
vv<ll> v;
f(i,0,n-1) { cin>>a[i]; if(a[i]<=t) v.push_back(a[i]);  m=min(a[i],m); }

ll k=0;
while(t>=m&&v.size()>0)
{ //map<ll,ll>::iterator it,it1 ;
ll sum=0;
f(i,0,v.size()-1)
{//cout<<v[i]<<" ";
 sum+=v[i];}
//cout<<sum<<endl;
if(sum<=t){
k+=(t/sum)*v.size();}
t%=sum;
//cout<<" "<<t;
 //for(it=v.begin();it!=v.end();it++) cout<<it->S<<" ";
 vv<ll> v1;
 f(i,0,v.size()-1) if(v[i]<=t) v1.push_back(v[i]);
if(v1.size()<=0) break;
 v.clear();
 f(i,0,v1.size()-1) v.push_back(v1[i]);


//else break;
//cout<<v.size();
 f(i,0,v.size()-1){
 if(v[i]<=t) {k++; t-=v[i]; }
 if(t<m) break;}


//cout<<t<<" "<<sum<<" "<<k<<" ";
}
cout<<k; exit(0);






    return 0;
}
