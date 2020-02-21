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

ll cn[1<<20+1][2];

int main()
{
    ll n;
    cin>>n;
    ll a[n+1];
    a[0]=0;
    f(i,1,n) cin>>a[i];
    ll pre[n+1];
    pre[0]=0;
    f(i,1,n)
    {
        pre[i]=a[i]^pre[i-1];
    }

    memset(cn,0,sizeof(cn));

    ll ans=0;
    f(i,0,n)
    {
        ans+=cn[pre[i]][i%2];
        cn[pre[i]][i%2]++;

    }
    cout<<ans<<endl;


}


