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
{ ll n;
cin>>n;
string s;
cin>>s;
ll a[26]={0};
f(i,0,n-2)
{
    if(s[i]!=s[i+1])
    {cout<<"YES"<<endl<<s[i]<<s[i+1]; exit(0);}
}
cout<<"NO";



    return 0;
}
