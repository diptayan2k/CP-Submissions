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
{
string s;
cin>>s;
ll n=s.length();
ll a[n];
//cout<<n;
f(i,0,n-1) a[i]=0;
for(ll i=0;i<n-1;i++)
{ if(s[i]!=s[i+1]) a[i]=1;
}
if(s[n-1]=='a') a[n-1]=1;
f(i,0,n-1) cout<<a[i]<<" ";
    return 0;
}
