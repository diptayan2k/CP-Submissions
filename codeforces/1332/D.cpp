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



void solve(ll t)
{
    ll k;
    cin>>k;
    cout<<2<<" "<<3<<endl;
    cout<<(1<<18)-1<<" "<<k<<" "<<(1<<17)<<endl<<(1<<17)<<" "<<(1<<17)+k<<" "<<k<<endl;

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
