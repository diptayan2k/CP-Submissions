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
   cin>>n;
   ll a[n];

   f(i,0,n-1) cin>>a[i];
   sort(a,a+n);
   map<ll,ll> m;
   f(i,0,n-1)
   f(j,0,n-1)
   if(i!=j) m[a[i]+a[j]]++;
   ll mm=0;
   f(i,0,n-1)
   f(j,0,n-1)
   if(i!=j) mm=max(m[a[i]+a[j]],mm);
   cout<<mm/2;

	return 0;
}
