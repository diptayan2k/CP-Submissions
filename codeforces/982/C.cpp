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

vector<ll> v[100001];
bool vis[100001];
ll n;
ll child[100001];
void dfs(ll u)
{
    vis[u]=true;
    //cout<<u<<" ";
    if(!v[u].empty())
    {
        f(i,0,v[u].size()-1)
        {
           if(!vis[v[u][i]])
           {
            dfs(v[u][i]);
            child[u]+=child[v[u][i]];
           }

        }
    }
}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
memset(vis, false , sizeof(vis));

cin>>n;
f(i,0,n-2)
{
    ll x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
}
f(i,1,n) child[i]=1;
dfs(1);
//f(i,1,n) child[i]--;
if(n%2==1) {cout<<-1; exit(0);}
ll ans=0;
f(i,1,n)
{
   //cout<<child[i]<<" ";
    if(child[i]%2==0) ans++;
}
//cout<<endl;
cout<<ans-1;
}
