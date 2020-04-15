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
     ll x,n,m;
     cin>>x>>n>>m;
     while(x>20 and n>0)
     {
         ll p=x/2+10;
         x=p;
         n--;
     }
     while(x>0 and m>0)
     {
         x-=10;
         m--;
     }
     if(x<=0)
     {
         cout<<"YES"<<endl;
     }
     else
     {
         cout<<"NO"<<endl;
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
