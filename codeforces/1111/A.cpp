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

bool isvowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    else
        return false;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
string s,t;
cin>>s>>t;
if(s==t)
    {cout<<"Yes";
exit(0);}
if(s.length()!=t.length())
{
    cout<<"No";
    exit(0);
}
f(i,0,s.length()-1)
{
    if(isvowel(s[i])&&!isvowel(t[i])) {cout<<"NO"; exit(0);}
     if(!isvowel(s[i])&&isvowel(t[i])) {cout<<"NO"; exit(0);}
}
cout<<"Yes";
	return 0;
}
