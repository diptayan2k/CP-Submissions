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

ll n,k;
vector<ll> v[200001];
ll lev[200001];
ll subtr[200001];
ll odr[200001];
ll sp[200001];

void dfs(ll u, ll par)
{
    lev[u]=lev[par]+1;
    subtr[u]=1;
    for(auto i:v[u])
    {
        if(i==par) continue;

        dfs(i,u);
        subtr[u]+=subtr[i];
    }


}

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.F==b.F)
    {
        if(lev[a.S]==lev[b.S])
        {
            return subtr[a.S]<subtr[b.S];
        }
        return lev[a.S]>lev[b.S];
    }
    return a.F>b.F;
}

void dfs1(ll u, ll par)
{

    for(auto i:v[u])
    {
        if(i==par) continue;
        dfs1(i,u);
        sp[u]+=sp[i];
    }


}

void solve(ll t)
{
    cin>>n>>k;
    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    lev[0]=-1;
    memset(subtr,0,sizeof(subtr));
    dfs(1,0);


    f(i,1,n) odr[i]=lev[i]-(subtr[i]-1);
    pair<ll, ll > p[n+1];
    f(i,1,n) p[i].F=odr[i], p[i].S=i;


    sort(p+1,p+n+1,cmp);
    //f(i,1,n) cout<<p[i].S<<" ";
    memset(sp,0,sizeof(sp));
    f(i,1,k) sp[p[i].S]=1;

    dfs1(1,0);

    ll ans=0;
    f(i,1,k)
    {
        ans+=lev[p[i].S]-(sp[p[i].S]-1);
    }
    cout<<ans<<endl;


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
