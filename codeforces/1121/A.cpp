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
using namespace std;


int main(){
   ll n,m,k;
   cin>>n>>m>>k;
   ll a[n];
   ll b[n];
   ll c[m]={0};
   f(i,0,n-1)
   cin>>a[i];
   f(i,0,n-1)
   cin>>b[i];
   ll d[k];
   f(i,0,k-1) cin>>d[i];
   f(i,0,n-1)
   c[b[i]-1]=max(c[b[i]-1],a[i]);
   ll coun=0;
   f(i,0,k-1)
   {
       f(j,0,m-1)
       if(a[d[i]-1]==c[j])
        coun++;
   }
   cout<<k-coun;


	return 0;
}
