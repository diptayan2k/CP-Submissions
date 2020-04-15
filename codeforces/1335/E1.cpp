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
vector<ll> v[201],vr[201];

void solve(ll t)
{
     ll n;
     cin>>n;
     ll a[n+1];

     set<ll> s;
     f(i,1,n)
     {
         cin>>a[i];
         v[a[i]].pb(i);
         s.insert(a[i]);
     }
     for(auto i:s)
     {
         vr[i]=v[i];
         reverse(vr[i].begin(),vr[i].end());
     }
     ll sz=s.size();
     map<ll,ll> fr[n+1];
     ll ffr[201];
     memset(ffr,0,sizeof(ffr));
     f(i,1,n)
     {
         ffr[a[i]]++;
         for(auto j:s) fr[i][j]=ffr[j];
     }
    /*
     f(i,1,n)
     {
         f(j,1,200)
         {
             cout<<fr[i][j]<<" ";
         }
         cout<<endl;
     }*/

     ll ans=0;

     for(auto i:s)
     {
         f(j,0,(v[i].size()-1)/2)
         {
             ll p=v[i][j];
             ll q=vr[i][j];
             ll ma=0;
             for(auto k:s)
             {
                 ans=max(ans,2*(j+1)+((q>p)?(fr[q-1][k]-fr[p][k]):0)-(p==q));
             }
         }
     }

     cout<<ans<<endl;

     f(i,0,200)
     {
         v[i].clear();
         vr[i].clear();
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
