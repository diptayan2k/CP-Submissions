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

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int main()
{
    ll n;
    cin>>n;
    ll a[n][2];
    f(i,0,n-1) cin>>a[i][0];
    f(i,0,n-1) cin>>a[i][1];
    ll dp[n][2];
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];

    f(i,1,n-1)
    {
        dp[i][0]=max(dp[i-1][1]+a[i][0],dp[i-1][0]);
        dp[i][1]=max(dp[i-1][0]+a[i][1],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;

}


