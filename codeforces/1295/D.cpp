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
ll n,x;
string s;

ll toitent(ll n)
{
    ll m=n;
    set s;
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }


    if (n > 2)
        s.insert(n);

    ll p=1;
    ll q=1;
    for(auto i:s)
    {
        p*=i;
        q*=(i-1);
    }
    return (m/p)*q;

}

int main()
{
ll t;


cin>>t;

while(t--)
{
    ll m,n;
    cin>>n>>m;
    ll d=__gcd(n,m);
    ll p=n/d;
    ll q=m/d;
    cout<<toitent(q)<<endl;

}
}
