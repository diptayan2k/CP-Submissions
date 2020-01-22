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


void solve()
{
    ll n,a,b,c;
    cin>>a>>b>>c>>n;
    ll p=max(a,max(b,c));
    ll d=p-a;
    ll e=p-b;
    ll f=p-c;
    n-=d;
    n-=e;
    n-=f;
    if(n<0) {cout<<"NO"<<endl; return;}
    if(n%3!=0) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;
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
