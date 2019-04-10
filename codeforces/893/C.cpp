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
   cin>>n>>m;

   bool vis[n+1];
   ll a[n+1];
   ll s=0;
   f(i,1,n) {cin>>a[i]; s+=a[i];}
   mi=s;
   f(i,0,n) vis[i]=false;
   vv<ll> v[n+1];
   f(i,0,m-1)
   { ll x,y;
   cin>>x>>y;
   v[x].pb(y);
   v[y].pb(x);
   }
   ll sum=0;
   f(i,1,n)
   {
       if(!vis[i])
       {  //if(v[i].empty()) {sum+=a[i]; vis[i]=true;}
            mi=s;
           sum+=dfs(v,vis,i,a);

       }
   }
   cout<<sum;
   //cout<<dfs(a,vis,1);
return 0;
}
/*
5 4
6 3 2 11
5 9 4 2
3 3 3 3
4 8 2 2
7 8 6 4
6 3 2 11
5 9 3 8
3 4 3 2
4 2 3 2
7 8 6 4
*/
