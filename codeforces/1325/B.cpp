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
 ll n;
 cin>>n;
 ll a[n];
 map<ll,ll> m;
 f(i,0,n-1)
 {
     cin>>a[i];
     m[a[i]]++;
 }
 cout<<m.size()<<endl;





}




int main()
{


    ll t=1;

    cin>>t;
    f(i,1,t)
    {
        solve(i);
    }

}
