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
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n,k;
cin>>n>>k;
string s;
cin>>s;
ll j=0;
f(i,0,n-2)
{if(s.substr(0,i+1)==s.substr(n-1-i,i+1)) j=i+1;
}
//cout<<j<<endl;
f(i,1,k-1)
s+=s.substr(j,n-j);
cout<<s;
	return 0;
}
