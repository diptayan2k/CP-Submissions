#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizof(arr))
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll mod= 998244353;
ll n,k;
ll dp[1001][2001][2][2];
//ll mod=998244353;
ll foo(ll idx, ll cmp , ll dig1, ll dig2)
{
    if(cmp>k) return 0;
    if(idx==n)
    {
        if(cmp==k) return 1;
        else return 0;
    }

    if(dp[idx][cmp][dig1][dig2]!=-1) return dp[idx][cmp][dig1][dig2]%mod;

    ll res=0;
    res=(res%mod+foo(idx+1, cmp+((dig1==1)&&(dig2==1)), 0, 0 )%mod)%mod;
    res=(res%mod+foo(idx+1, cmp+(dig1!=0)+(dig2!=1), 0, 1 )%mod)%mod;
    res=(res%mod+foo(idx+1, cmp+(dig1!=1)+(dig2!=0), 1, 0 )%mod)%mod;
    res=(res%mod+foo(idx+1, cmp+((dig1==0)&&(dig2==0)), 1, 1 )%mod)%mod;

    return dp[idx][cmp][dig1][dig2]=res%mod;

}

void solve(ll t)
{
    cin>>n>>k;
    f(i,0,1000) f(j,0,2000) f(k,0,1) f(l,0,1) dp[i][j][k][l]=-1;

    cout<<(foo(1,1,0,0)%mod+foo(1,2,0,1)%mod+foo(1,2,1,0)%mod+foo(1,1,1,1)%mod)%mod;

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

