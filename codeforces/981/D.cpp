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
ll mod=1000000007;
ll n,k;
ll a[51];
ll pr[51];
bool dp[52][52][52];
bool vis[52][52][52];

bool foo(ll idx, ll pre,ll cn, ll x)
{
    if(cn>k)
    {
        return false;
    }
    if(idx==n+1)
    {
        if(cn==k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if(vis[idx][pre][cn]) return dp[idx][pre][cn];

    bool res;

    ll p=pr[idx]-pr[pre];

    if(idx==n)
    {
        if((p&x)!=x)
        {
            res=false;
            vis[idx][pre][cn]=true;
            return dp[idx][pre][cn]=res;
        }
        else
        {
            res=(foo(idx+1,idx,cn+1,x));
            vis[idx][pre][cn]=true;
            return dp[idx][pre][cn]=res;
        }

    }
    else if((p&x)==x)
    {
        res=(foo(idx+1,idx,cn+1,x)|foo(idx+1,pre,cn,x));
        vis[idx][pre][cn]=true;
        return dp[idx][pre][cn]=res;

    }
    else
    {
        res=(foo(idx+1,pre,cn,x));
        vis[idx][pre][cn]=true;
        return dp[idx][pre][cn]=res;
    }

}

void solve(ll t)
{
    cin>>n>>k;
    f(i,1,n) cin>>a[i];
    pr[0]=0;
    f(i,1,n)
    {
        pr[i]=pr[i-1]+a[i];
        //cout<<pr[i]<<" ";
    }

    ll ans=0;
    g(i,60,0)
    {
        memset(dp,false,sizeof(dp));
        memset(vis,false,sizeof(vis));
        if(foo(1,0,0,(ans|(1ll<<i))))
        {
            //cout<<i<<endl;
            ans|=(1ll<<i);
        }


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

