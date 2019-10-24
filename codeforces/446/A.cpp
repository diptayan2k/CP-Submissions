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
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;
ll mod=1000000007;



int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
if(n==1) {cout<<1; exit(0);}
ll b[n];
ll c[n];
b[0]=1;
c[n-1]=1;

f(i,1,n-1)
{
    if(a[i]>a[i-1]) b[i]=b[i-1]+1;
    else b[i]=1;
}
g(i,n-2,0)
{
    if(a[i]<a[i+1]) c[i]=c[i+1]+1;
    else c[i]=1;
}

ll ans1=b[n-2]+1;
ll ans2=c[1]+1;
ll ans=0;
f(i,1,n-2)
{
    if(a[i-1]+1<a[i+1]) ans=max(ans,b[i-1]+c[i+1]+1);
    else ans=max(ans,max(b[i-1]+1,c[i+1]+1));
    //cout<<b[i]<<" "<<c[i]<<endl;
}

ans1=max(ans1,ans2);
cout<<max(ans,ans1);



}
