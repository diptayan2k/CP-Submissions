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

ll mod=1000000000000000+7;
bool dp[501][501][501];
ll n,k;
ll a[501];
vector<ll> v;

void solve(ll d)
{

    cin>>n>>k;
    f(i,1,n) cin>>a[i];
    a[0]=0;

    f(i,0,500) f(j,0,500) f(l,0,500) dp[i][j][l]=false;


    dp[0][0][0]=true;
    //f(i,0,n) f(j,0,k) dp[i][j][0]=true;



    f(i,1,n)
    {
        f(j,0,k)
        {
            f(l,0,k)
            {
                bool res;
                res=dp[i-1][j][l];
                if(j>=a[i]) {res|=dp[i-1][j-a[i]][l]; if(l>=a[i]) res|=dp[i-1][j-a[i]][l-a[i]]; }

                dp[i][j][l]=res;
            }

        }
    }

    f(i,0,k)
    {
        if(dp[n][k][i]) v.pb(i);
    }
    cout<<v.size()<<endl;
    for(auto i:v) cout<<i<<" ";

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



