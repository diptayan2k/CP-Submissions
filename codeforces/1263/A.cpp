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
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    ll p = a[2]-a[1];
    //cout<<p<<endl;
    if(p<=a[0])
    {
        ll ans=p;
        a[0]-=p;
        a[2]=a[1];
        ll d=a[0]/2;
        ll e = a[0]-d;
        ans+=a[0];
        a[2]-=e;
        a[1]-=d;
        //cout<<e<<" "<<d<<endl;
        cout<<ans+min(a[2],a[1])<<endl;

    }
    else
    {

        cout<<a[0]+a[1]<<endl;
    }
}


return 0;
}









