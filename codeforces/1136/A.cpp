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
   ll n;

   ll k;
   cin>>n;
   pair<ll,ll> a[n];
   f(i,0,n-1) cin>>a[i].F>>a[i].S;
   cin>>k;
   ll ans;
   f(i,0,n-1)
   if(k>=a[i].F&&k<=a[i].S)
   {
       ans=n-i;
   }
  cout<<ans;
	return 0;
}
