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
#define pb push_back
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   ll n;
   cin>>n;
   ll x,y;
   cin>>x>>y;

   ll ww=min(x,y)-1+max(x,y)-min(x,y);
   ll bb=n-max(x,y)+max(x,y)-min(x,y);
   if(ww>bb) cout<<"black";
   else cout<<"white";
	return 0;
}

