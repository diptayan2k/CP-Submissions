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




ll solve()
{
    ll n,s,k;
    cin>>n>>s>>k;
    ll a[k];
    map<ll,ll> m;
    f(i,0,k-1) {cin>>a[i]; m[a[i]]=1;}
    ll ans1=n;
    ll ans2=n;
    ll i=0;
    while(m[s+i]&&(s+i)<=n)
    {
        i++;
    }
    if(!m[s+i]&&(s+i)<=n)
    ans1=i;

    i=0;
    while(m[s-i]&&(s-i)>=1)
    {
        i++;
    }
    if(!m[s-i]&&(s-i)>=1)
    ans2=i;
    //cout<<ans2<<" "<<ans1<<endl;
    cout<<min(ans1,ans2)<<endl;





}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
while(t--)
{
    solve();
}
}
