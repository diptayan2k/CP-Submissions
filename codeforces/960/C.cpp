#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcount(x)
using namespace std;
ll mod=1000000007;


void solve(ll t)
{
    ll x,d;
    cin>>x>>d;
    vector<ll> v;
    ll q=1;
    g(i,30,0)
    {
        if((x&(1ll<<i))!=0)
        {

            f(j,1,i)
            {
                v.pb(q);
            }
            q+=d;
        }
    }
    ll p=bits(x);
    f(i,1,p)
    {
        v.pb(q);
        q+=d;
    }
    cout<<v.size()<<endl;
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;






}


int main()
{
    ll t=1;
    //scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}

