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

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n-1) cin>>a[i];
    ll b[n];


    ll d[n];
    f(i,0,n-1) d[i]=i;
    ll e[n];
    f(i,0,n-1) e[i]=n-1-i;
    ll ff=0;
    f(i,0,n-1)
    {
        if(a[i]<d[i])
            {
                ff=1;
            }

    }
    if(ff==0)
    {
        cout<<"Yes"<<endl;
        return;
    }

    ff=0;
    f(i,0,n-1)
    {
        if(a[i]<e[i])
            {
                ff=1;
            }

    }
    if(ff==0)
    {
        cout<<"Yes"<<endl;
        return;
    }
    ll ma=-1;

    f(i,0,n-1)
    {
        if(a[i]<i) {ma=i; break;}
    }
    if(ma!=-1)
    {
        ma--;
        b[ma]=a[ma];
        g(i,ma-1,0) b[i]=min(b[i+1]-1,a[i]);
        f(i,ma+1,n-1) b[i]=min(b[i-1]-1,a[i]);
    }

    //f(i,0,n-1) cout<<b[i]<<" ";

    f(i,0,n-1)
    {
        if(a[i]<b[i]||b[i]<0)
        {
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;


}

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       solve();
   }

}
