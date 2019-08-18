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
vv<ll> s;


void dfs(vv<ll> vv[],bool vis[],ll u, ll v)
{  s.pb(u);
   if(u==v) return;
      vis[u]=true;
      if(u==v) return;

   ll ff=0;
    if(!vv[u].empty())
    f(j,0,vv[u].size()-1)
    if(!vis[vv[u][j]])
    {
    dfs(vv,vis,vv[u][j],v);
    ff=1;
    }
    if(ff==0) s.pop_back();



}

void initialize( ll Arr[ ], ll N, ll size[])
{
    for(ll i = 1;i<=N;i++)
    {
Arr[ i ] = i ;
size[ i ] = 1;
}
}

ll root (ll Arr[ ] ,ll i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
i = Arr[ i ];
    }
return i;
}

void unio(ll Arr[ ],ll size[ ],ll A,ll B)
{
    ll root_A = root(Arr,A);
    ll root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];

}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}

}






int main(){
ll n,m;
cin>>n;
if(n%2==0)
{
    cout<<"NO"; exit(0);
}
else{
    cout<<"YES"<<endl;
    ll a[n-1][2];
    ll k=3;
    f(i,0,n-2)
    { a[i][0]=k++;
      a[i][1]=k++;
    }
    for(ll i=0;i<n-1;i+=2)
    { swap(a[i][0],a[i][1]);
    }
    cout<<1<<" ";
    f(i,0,n-2) cout<<a[i][0]<<" ";
    cout<<2<<" ";
    f(i,0,n-2) cout<<a[i][1]<<" ";
}
}

/*
1
6
1 2 3
5 1
5 6
1 3
6 2
6 4
*/










