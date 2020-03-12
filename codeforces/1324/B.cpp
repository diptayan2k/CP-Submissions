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
ll mod=1000000007;

void solve(ll t)
{

    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n-1) cin>>a[i];
    ll dp[n][n];
    init(dp,0);
    f(i,0,n-1) dp[i][i]=1;

    f(k,1,n-1)
    {
        f(i,0,n-1)
        {
            ll j=i+k;
            if(j<n){
            if(a[i]==a[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }}
        }
    }
    if(dp[0][n-1]>=3)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


}


int main()
{
    ios::sync_with_stdio(0);
    ll t=1;
    cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}


