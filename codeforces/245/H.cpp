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




void solve(ll t)
{
    char s[5000];
    scanf("%s",s);
    ll n=strlen(s);

    ll dp[n][n];
    bool ispal[n][n];
    init(dp,0);
    init(ispal,0);
    f(i,0,n-1) {ispal[i][i]=1; dp[i][i]=1;}
    f(k,1,n-1)
    {
        f(i,0,n-k)
        {
            ll j=i+k;
            if(j<n)
            {
               if(s[i]==s[j]){ ispal[i][j]=ispal[i+1][j-1]; if(i+1==j) ispal[i][j]=1; }
               else ispal[i][j]=0;
               if(i+1==j) dp[i][j]=dp[i+1][j]+dp[i][j-1]+ispal[i][j];
               else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+ispal[i][j];
            }
        }


    }


    /*
    f(i,0,n-1)
    {
        f(j,0,n-1) cout<<ispal[i][j]<<" ";
        cout<<endl;
    }*/

    ll q;
    scanf("%lld",&q);

    while(q--)
    {
        //cout<<q<<endl;
        ll l,r;
        scanf("%lld",&l);
        scanf("%lld",&r);

        printf("%lld\n",dp[l-1][r-1]);

    }

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


