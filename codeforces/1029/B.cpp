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
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
vv <ll> s;
ll m=0;
f(i,0,n-1)
{
    if(s.empty()) s.pb(a[i]);
    else if(a[i]<=2*s[s.size()-1]) { s.pb(a[i]);}
    else {s.clear(); s.pb(a[i]);}
 m=max((ll)s.size(),m);
//if(!s.empty()){f(i,0,s.size()-1) cout<<s[i]<<" ";
//cout<<endl;}
}
cout<<m;
	return 0;
}
