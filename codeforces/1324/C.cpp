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
ll mod=1000000007;

void solve(ll t)
{

    string s;
    cin>>s;
    ll n=s.length();
    vector<ll> v;
    v.pb(0);
    f(i,0,n-1)
    {
        if(s[i]=='R') v.pb(i+1);
    }
    v.pb(n+1);
    ll ma=0;
    f(i,1,v.size()-1)
    {
        ma=max(ma,v[i]-v[i-1]);
    }
    cout<<ma<<endl;


}


int main()
{
    ios::sync_with_stdio(0);
    ll t=1;
    cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}


