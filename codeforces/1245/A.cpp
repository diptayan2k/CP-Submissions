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
ll t;
cin>>t;
while(t--)
{
    ll a,b;
    cin>>a>>b;
    if(__gcd(a,b)==1) cout<<"Finite"<<endl;
    else cout<<"Infinite"<<endl;

}
}
