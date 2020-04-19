#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcount(x)
using namespace std;
ll n;
vector<ll> v[100001];
ll a[100001]={0};
ll lev[100001]={0};

void dfs(ll u , ll par)
{
    if(v[u].size()==1) a[par]=1;

    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs(i,u);
    }
}

void dfs1(ll u , ll par)
{
    lev[u]=lev[par]+1;

    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs1(i,u);
    }
}


void solve(ll t)
{
    cin>>n;
    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll leaf=0;
    ll lf;
    f(i,1,n) if(v[i].size()==1) {leaf++; lf=i;}
    ll root;
    f(i,1,n) if(v[i].size()>1) {root=i; break;}
    dfs(root,0);
    lev[0]=-1;
    dfs1(lf,0);
    ll mi=1;
    f(i,1,n)
    {
        if(v[i].size()==1 and lev[i]%2==1)
        {
            mi=3;
            break;
        }
    }
    ll cn=0;
    f(i,1,n) cn+=a[i];
    ll mx=n-1-leaf+cn;
    cout<<mi<<" "<<mx<<endl;


}


int main()
{
    ll t=1;
    //scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}

