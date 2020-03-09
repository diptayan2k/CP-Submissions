#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
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

ll n1,n2,k1,k2;
ll dp[101][101][11][11];
ll mod=100000000;
ll foo(ll i, ll j, ll k, ll l)
{
    if(i==n1 and j==n2)
    {
        return 1;
    }
    if(i>n1 or j>n2) return 0;

    if(dp[i][j][k][l]!=-1)
    {
        return dp[i][j][k][l];

    }

    ll res=0;
    if(k<k1)
    res=(res%mod+foo(i+1,j,k+1,0)%mod)%mod;
    if(l<k2)
    res=(res%mod+foo(i,j+1,0,l+1)%mod)%mod;


    return dp[i][j][k][l]=res%mod;
}


void solve(ll t)
{
    f(i,0,100) f(j,0,100) f(k,0,10) f(l,0,10) dp[i][j][k][l]=-1;
    cin>>n1>>n2>>k1>>k2;
    cout<<foo(0,0,0,0);


}








int main()
{
    ios::sync_with_stdio(0);
    ll t=1;
    f(i,1,t)
    {
        solve(i);
    }

}


