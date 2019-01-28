#include <iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
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
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

char a[26],A[26];
f(i,0,26-1) a[i]=i+97;
f(i,0,26-1) A[i]=i+65;

ll t;
cin>>t;
while(t--)
{
    ll a,b;
    cin>>a>>b;
    if(b==9)
    {
        cout<<a*9<<endl;
    }
    else
    {
        cout<<(a-1)*9+b<<endl;
    }
}
	return 0;
}
