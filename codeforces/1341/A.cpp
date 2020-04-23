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
#define bits(x) __builtin_popcountll(x)
using namespace std;
ll mod=1000000007;


void solve(ll t)
{
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    ll p=a-b;
    ll q=a+b;
    ll r=c-d;
    ll s=c+d;

    p*=n;
    q*=n;
    //cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
    if(q<r or p>s)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }




}


int main()
{
    ll t=1;
    scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}

