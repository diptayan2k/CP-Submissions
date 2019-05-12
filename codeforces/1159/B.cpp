#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,b,a) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
ll mi;
ll m;

ll s=0;
//vv<ll> m;
void dfs(vv<ll> v[],bool vis[],ll i,ll sum[],ll a[], ll c[])
{
      vis[i]=true;
     sum[i]=a[i];
     c[i]=0;

    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs(v,vis,v[i][j],sum,a,c);
    sum[i]+=sum[v[i][j]];
    c[i]++;
    }



}
ll p;
void dfs1(vv<ll> v[],bool vis[],ll i,ll sum[],ll c[], ll a[])
{
      vis[i]=true;


    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs1(v,vis,v[i][j],sum,c,a);
    s=max(s,s-sum[v[i][j]]-m);
    }
    p=p-sum[i]-m;
    s=max(s,p);




}



int main(){
ll n;
cin>>n;
/*pair<ll,ll> a[n];
f(i,0,n-1)
{cin>>a[i].F;
a[i].S=i+1;}
sort(a,a+n);
cout<<a[0].F/max((a[0].S-1),(n-a[0].S));*/
ll c=1000000000;
ll a[n];
f(i,0,n-1) cin>>a[i];
f(i,0,n-1)
{ if(a[i]==0) c=0;
else
    c=min(c,a[i]/max(i,n-i-1));
//cout<<c<<" ";
}
cout<<c;
return 0;
}

/*
2
3 5
1 -5 -10
1 2
2 3
6 5
1 -2 4 -6 8 10
1 2
1 3
3 4
3 5
3 6
*/
