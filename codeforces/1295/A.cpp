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

vector<ll> v[1001];
ll dis[1001];
bool vis[1001];

ll m=1000000007;


ll power(ll x,ll y)
{
    if (y==0)
        return 1;
    ll p=power(x, y/2) % m;
    p = (p%m * p%m)%m;

    return (y%2 == 0)? p : (x%m * p%m) % m;
}

int main()
{
ll t;
cin>>t;

while(t--)
{
    ll n;
    cin>>n;
    if (n & 1) {

        cout << "7";


        for (ll i = 0; i < (n - 3) / 2; i++)
            cout << "1";
    }


    else {

        for (ll i = 0; i < n / 2; i++)
            cout << "1";
    }
cout<<endl;
}
}
