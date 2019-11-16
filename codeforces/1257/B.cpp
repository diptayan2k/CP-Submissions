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
/*
ll mod=1000000007;
ll si=0;
vector<ll> v[100000];
bool vis[100000];

void dfs(ll u)
{  cout<<u<<" ";
    vis[u]=true;
  si++;
 if(!v[u].empty())
 {
     f(i,0,v[u].size()-1)
     {
         if(!vis[v[u][i]])
            dfs(vis[v[u][i]]);
     }
 }

}
*/


int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
while(t--)
{
    ll x,y;
    cin>>x>>y;
    if(x==1&&y>1)
    {
        cout<<"NO"<<endl;
        continue;
    }
    if(x==2&&y>3)
    {
        cout<<"NO"<<endl;
        continue;
    }
    if(x==3&&y>3)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;


}



}
