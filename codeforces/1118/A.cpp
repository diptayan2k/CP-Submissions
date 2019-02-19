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
   ll q;
   cin>>q;
   while(q--)
   { ll n,a,b;
   cin>>n>>a>>b;
   ll p=(n/2)*b+(n%2)*a;
   ll q=n*a;

   cout<<min(p,q)<<endl;

   }
	return 0;
}
