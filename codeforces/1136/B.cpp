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
   cin>>n>>k;

    k=min(k,n-k+1);
        cout<<(k-1)*2+(n-k)+2*n+1;
	return 0;
}
