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
ll m = 1000000007;
int power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % m;
    p = (p %m* p%m) % m;

    return (y%2 == 0)? p%m : (x%m * p%m) % m;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,mm;
cin>>n>>mm;
ll a = n+2*mm-1;
ll b=2*mm;
ll c = n-1;
ll fact[2001];
fact[0]=1;
f(i,1,2000)
{
    fact[i]=(fact[i-1]%m*i%m)%m;

}
ll d = fact[a];
ll e = (fact[b]%m*fact[c]%m)%m;

//cout<<d<<" "<<e<<" ";
cout<<(d*power(e,m-2)%m)%m;



}













