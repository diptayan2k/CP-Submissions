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
#define bits(x) __builtin_popcountll(x)
using namespace std;
ll mod=1000000007;

ll n,k;

ll a[2001];
ll mpp[10];
ll ans[2001];
bool dp[2001][2001], vis[2001][2001];


bool foo(ll idx, ll cn)
{
    if(cn>k)
    {
        return false;
    }
    if(idx==n)
    {
        if(cn==k) return true;
        return false;
    }

    if(vis[idx][cn])
    {
        return dp[idx][cn];
    }

    bool res=false;

    g(i,9,0)
    {
        if((mpp[i]&a[idx])==a[idx])
        {
            ll p=bits(mpp[i])-bits(a[idx]);
            res=foo(idx+1,cn+p);
            if(res)
            {
                ans[idx]=i;
                vis[idx][cn]=true;
                return dp[idx][cn]=res;
                break;
            }
        }
    }
    vis[idx][cn]=true;
    return dp[idx][cn]=res;


}

map<ll,ll> m;
string p[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

void solve(ll t)
{

    cin>>n>>k;

    f(i,0,n-1)
    {
        string s;
        cin>>s;
        ll val=0;
        f(j,0,s.length()-1)
        {
            if(s[j]=='1') val|=(1ll<<j);
        }
        a[i]=val;
    }

    f(i,0,9)
    {
        string s=p[i];
        ll val=0;
        f(j,0,s.length()-1)
        {
            if(s[j]=='1') val|=(1ll<<j);
        }
        mpp[i]=val;


    }

    memset(vis,false,sizeof(vis));

    if(!foo(0,0))
    {
        cout<<-1<<endl;
        return;
    }

    f(i,0,n-1) cout<<ans[i];
    cout<<endl;







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

