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






int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll n,m;
cin>>n>>m;
ll a[n];
ll b[n];
ll d[n];
f(i,0,n-1) cin>>a[i];
f(i,0,n-1) cin>>b[i];
f(i,0,n-1)
{
    if(b[i]>=a[0]) d[i]=b[i]-a[0];
    else d[i]=b[i]+m-a[0];
}

//f(i,0,n-1) cout<<d[i]<<" ";
vector<ll> v;

f(i,0,n-1) v.pb(b[i]);
sort(v.begin(),v.end());
sort(d,d+n);

for(auto i:d)
{
    vector<ll> ans;
    for(auto j:a)
    {
        ans.pb((i+j)%m);
    }
    sort(ans.begin(),ans.end());
    if(ans==v)
    {
        cout<<i;
        exit(0);
    }

}

}
