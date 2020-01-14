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



ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n-1) cin>>a[i];
    map<ll,ll> m;
    ll ans=0;
    f(i,0,n-1)
    {

        ll c=0;
        ll x = a[i];
        while(x%2==0&&m[x]==0)
        {
            m[x]=1;
            x/=2;
            c++;

        }
        ans+=c;


    }
    cout<<ans<<endl;




}



}



/*

3 7
1 2 3 2 6 1 3

*/



