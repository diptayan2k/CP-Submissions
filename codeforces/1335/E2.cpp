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
     int n;
     cin>>n;
     int a[n+1];
     vector<int> v[201],vr[201];
     set<int> s;
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
     int fr[n+1][201];
     memset(fr,0,sizeof(fr));
     int ffr[201];
     memset(ffr,0,sizeof(ffr));
     f(i,1,n)
     {
         ffr[a[i]]++;
         f(j,1,200) fr[i][j]=ffr[j];
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

     int ans=0;

     for(auto i:s)
     {
         f(j,0,(v[i].size()-1)/2)
         {
             int p=v[i][j];
             int q=vr[i][j];
             int ma=0;
             for(auto k:s)
             {
                 ans=max(ans,2*(j+1)+((q>p)?(fr[q-1][k]-fr[p][k]):0)-(p==q));
             }
         }
     }

     cout<<ans<<endl;






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
