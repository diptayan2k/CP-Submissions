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

/*vector<ll> v[100001];
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
*/
int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
string s;
cin>>s;
ll a[n];
f(i,0,n-1)
{
    if(s[i]=='1') a[i]=1;
    else a[i]=-1;
}
ll b[n];
ll sum =0;
map<ll,ll> m;
ll k=0;
vector<ll> v[n+1];

f(i,0,n-1)
{
    sum+=a[i];
    if(!m[sum]) m[sum]=++k;

    b[i]= sum;
}
v[m[0]].pb(0);
f(i,0,n-1)
{
    v[m[b[i]]].pb(i+1);
}
ll len=0;
f(i,1,n)
{
    if(!v[i].empty())
    {
        len=max(v[i][v[i].size()-1]-v[i][0],len);
    }
}
cout<<len;

}
