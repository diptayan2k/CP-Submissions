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
//   ll m=0;
   f(i,0,n-1)
   {cin>>a[i];
   }
   sort(a,a+n,greater<int>());
   ll p=m/(k+1);
   ll ans=p*(k*a[0]+a[1]);
   ans+=(m%(k+1))*a[0];
   cout<<ans;

	return 0;
}
