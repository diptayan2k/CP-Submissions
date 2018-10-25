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
ll a[n+1];
ll b[n+1];
ll d[n+1];
f(i,1,n) { cin>>a[i]; d[a[i]]=i;}
f(i,1,n) cin>>b[i];
ll s=0;
ll c[n+1]={0};
c[1]=d[b[1]];
ll m=d[b[1]];
s=c[1];
f(i,2,n)
{// cout<<d[b[i]]<<" "<<m<<endl;
if(d[b[i]]>m){c[i]=d[b[i]]-s; m=d[b[i]];}
else c[i]=0;
s+=c[i];

}
f(i,1,n) cout<<c[i]<<" ";


    return 0;
}
