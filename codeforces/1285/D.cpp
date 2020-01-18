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




ll solve(ll bit, vector<ll> v)
{
    if(bit<0) return 0;
    vector<ll> on,off;
    for(ll i:v)
    {
        if(i&(1<<bit)) on.pb(i);
        else off.pb(i);
    }
    if(on.empty()) return solve(bit-1, off);
    if(off.empty()) return solve(bit-1, on);
    return min(solve(bit-1, on),solve(bit-1, off))+(1<<bit);


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;
cin>>n;
vector<ll> a;
f(i,0,n-1)
{

   ll x;
   cin>>x;
   a.pb(x);
}

cout<<solve(30,a);

}
