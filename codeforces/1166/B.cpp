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
ll k;
cin>>k;
ll a,b;
ll f=1;
f(i,5,k-1)
{
    if(k%i==0)
    {  if(k/i>=5){
        a=k/i;
        b=i;
        f=0;
        goto z;}
    }
}
z:
if(f==1) {cout<<-1; exit(0);}
string s="aeiou";
//cout<<a<<" "<<b;
f(i,0,b-1)
{f(j,0,a-1)
cout<<s[(j+i)%5];
}
return 0;
}


