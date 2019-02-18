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
   ll m=0;
   f(i,0,n-1)
   {cin>>a[i];
    m=max(a[i],m);}
   ll d=0,md=0;
   f(i,0,n-1)
   { if(a[i]==m)
    {d++;
     md=max(d,md);
    }
    else d=0;

   }

   cout<<md;
	return 0;
}
