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
#define bits(x) __builtin_popcount(x)
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll mod=1e9+7;

void solve(ll t)
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    ll p=b-a;
    ll q=d-c;

    if(x1==x and x2==x)
    {
        if(a!=0 and b!=0)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    if(y1==y and y2==y)
    {
        if(c!=0 and d!=0)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    x+=p;
    y+=q;
    if(x1<=x and x<=x2 and y1<=y and y<=y2)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    cin>>t;

    f(i,1,t)
    {
        solve(i);
    }

}

