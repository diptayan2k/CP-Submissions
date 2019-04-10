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
ll dfs(vv<ll> v[],bool vis[],ll i,ll a[])
{
      vis[i]=true;
      mi=min(mi,a[i]);
  //cout<<i<<" ";
    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs(v,vis,v[i][j],a);
    }

    return mi;

}

int main(){
   ll n,m;
   cin>>n;

   bool vis[n+1];
   ll a[n+1];

   f(i,1,n) {cin>>a[i]; ;}

   f(i,0,n) vis[i]=false;
 ll   ma=0;
   f(i,1,n)
   { ll x;
     ll c=1;
     x=i;
    while(a[x]!=-1)
    { x=a[x];
    c++;
     //cout<<x<<" ";
     }
     //cout<<endl;
     ma=max(ma,c);


   }
   cout<<ma;
   //cout<<dfs(a,vis,1);
return 0;
}
