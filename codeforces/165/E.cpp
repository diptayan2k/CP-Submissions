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
#define set set <ll, greater<ll> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;



ll fr[1<<22];
//ll dp[1<<22][23];
//ll sos[1<<22];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n-1) cin>>a[i];
    //cout<<(1<<22)<<endl;
    f(i,0,(ll)(1<<22)-1) fr[i]=-1;


    for(auto i:a)
    {
        fr[i]=i;
    }
    //f(i,0,100) cout<<i<<" : "<<fr[i]<<endl;




    /*
    f(mask,0,(ll)(1<<22)-1)
    {
        if(fr[mask]!=-1)
        dp[mask][0]=fr[mask];
        if(mask&1&&fr[mask^1]!=-1) dp[mask][0]=fr[mask^1];
        f(p,1,22)
        {
            if(dp[mask][p-1]!=-1) dp[mask][p]=dp[mask][p-1];
            else if((mask&(1<<p))&&dp[mask^(1<<p)][p-1]!=-1)
               dp[mask][p]=dp[mask^(1<<p)][p-1];

        }

    }*/


    for(ll i = 0;i < 23; ++i)
        for(ll mask = 0; mask < (1<<22); ++mask)
            {
            if(mask&(1<<i))
                if(fr[mask^(1<<i)]!=-1) fr[mask] = fr[mask^(1<<i)];
            }

    ll ans=0;


    //dp[a[i]^(1<<22)

    f(i,0,n-1)
    {
        ans=fr[((ll)(1<<22)-1)^a[i]];

            cout<<ans<<" ";

    }



    //cout<<2*ans<<endl;




}












