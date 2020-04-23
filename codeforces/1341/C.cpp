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
    ll n;
    cin>>n;
    ll a[n+1];
    f(i,1,n) cin>>a[i];
    ll b[n+1];
    f(i,1,n) b[a[i]]=i;
    ll pos=0;
    f(i,1,n)
    {
        ll p=b[i];
        if(pos!=0 and p!=pos)
        {
            cout<<"No"<<endl;
            return;
        }
        if(p==n)
        {
            pos=0;
        }
        else if(a[p+1]<i)
        {
            pos=0;
        }
        else
        {
            pos=p+1;
        }

    }
    cout<<"Yes"<<endl;




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

