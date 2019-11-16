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
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    f(i,0,n-1) cin>>a[i];
    f(i,0,n-1) cin>>b[i];
    ll c[n];
    f(i,0,n-1)
    c[i]=b[i]-a[i];
    ll flag=0;
    ll ff=0;
    map<ll,ll> m;
    f(i,0,n-1)
    {
        if(c[i]<0) flag=1;
        if(c[i]>0) m[c[i]]++;
    }
    if(m.size()>1) flag=1;

    vector<ll> v;
    f(i,0,n-1)
    {
        if(c[i]>0) v.pb(i);
    }
    if(v.size()>1)
    {
        f(i,1,v.size()-1)
        if(v[i]-v[i-1]!=1) flag=1;
    }
    if(flag==1)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;



}



}
