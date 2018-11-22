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
ll n,s;
cin>>n>>s;
ll b=s/n;
ll c=s%n;
if(c!=0) b++;
cout<<b;

	return 0;
}

