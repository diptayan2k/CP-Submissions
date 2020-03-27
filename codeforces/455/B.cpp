#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcount(x)
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll tri[100001][26];
bool win[100001],lose[100001];
void dfs(ll u)
{

    win[u]=false;
    lose[u]=false;
    ll s=0;
    f(i,0,25)
    {
        if(tri[u][i]!=0)
        {
            dfs(tri[u][i]);
            win[u]|=!(win[tri[u][i]]);
            lose[u]|=!(lose[tri[u][i]]);
            s++;
        }
    }
    if(s==0)
    {
        lose[u]=true;
    }
}

void solve(ll t)
{
    memset(tri,0,sizeof(tri));

    ll n,k;
    cin>>n>>k;
    ll m=1;
    ll u=0;
    f(i,0,n-1)
    {
        string s;
        cin>>s;
        u=0;
        for(auto ch: s)
        {
            if(!tri[u][ch-'a'])
                tri[u][ch-'a']=m++;
            u=tri[u][ch-'a'];
        }

    }
    dfs(0);


    if(win[0] and lose[0])
    {
        cout<<"First"<<endl;
        return;
    }
    if(!win[0])
    {
        cout<<"Second"<<endl;
        return;
    }
    if(win[0] and !lose[0])
    {
        if(k%2==1)
        {
            cout<<"First"<<endl;
            return;
        }
        else
        {
            cout<<"Second"<<endl;
            return;
        }
    }





}

int main()
{
    ll t=1;
    //cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}






