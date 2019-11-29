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
    set s;
    s.insert(0);
    for (ll i=1; i*i<= n;i++)
    {
        ll a= n/i;
        ll b=n/a;
        s.insert(a);
        s.insert(b);
    }
    set ::iterator it;
    vector<ll> v;
   // v.pb(0);
    for(it=s.begin(); it!=s.end();it++)
        v.pb(*it);

    cout<<v.size();
    cout<<endl;

    g(i,v.size()-1,0)
    cout<<v[i]<<" ";
    cout<<endl;


}


return 0;
}









