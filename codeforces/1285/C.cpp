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

ll x;
cin>>x;
vector<ll> v;
f(i,1,sqrt(x))
{
    if(x%i==0)
    {
        v.pb(i);

    }
}
ll ans = x;

//for(auto i: v) cout<<i<<" ";

for(auto i:v)
{
ll    j=x/i;
    {
        if(i*j/__gcd(i,j)==x)
        {
            ans= min(ans,max(i,j));

        }
    }
}
cout<<ans<<" "<<x/ans;


}













