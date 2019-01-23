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
ll q;
cin>>q;
while(q--)
{ pair<ll,ll> a[2],b[2];
    cin>>a[0].F>>a[0].S>>a[1].F>>a[1].S;
f(i,0,1) {b[i].F=a[i].F; b[i].S=a[i].S;}
sort(a,a+2);
if(b[0].F==a[0].F&&b[0].S==a[0].S&&b[1].F==a[1].F&&b[1].S==a[1].S)
cout<<a[0].F<<" "<<a[1].S<<endl;
else cout<<a[1].S<<" "<<a[0].F<<endl;
}
	return 0;
}
