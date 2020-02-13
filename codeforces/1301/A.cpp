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

ll mod=1000000007;

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % mod;
    p = (p%mod * p%mod) % mod;

    return (y%2 == 0)? p%mod : (x%mod * p%mod) % mod;
}

void solve()
{
     string a,b,c;
    cin>>a>>b>>c;
    ll n=a.length();
    f(i,0,n-1)
    {
        if(a[i]!=c[i]) swap(a[i],c[i]);
        else swap(b[i],c[i]);
    }
    if(a==b)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

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
