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

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
 ll n;
 cin>>n;
 string s1, s2;
 map<char,ll> m1,m2;
 cin>>s1;
 cin>>s2;
 for(auto i: s1) m1[i]++;
 for(auto i: s2) m2[i]++;

 vector<pair<ll,ll> > v;

 f(i,0,n-1)
 {

     if(s1[i]!=s2[i])
     {
         f(j,i+1,n-1)
         {
             if(s1[j]==s1[i])
             {
                 swap(s1[j],s2[i]);
                 v.pb({j+1,i+1});
                 break;
             }
         }

     }
     if(s1[i]!=s2[i])
     {
         f(j,i+1,n-1)
         {
             if(s2[j]==s1[i])
             {
                 swap(s2[j],s1[n-1]);
                 v.pb({n,j+1});
                 swap(s1[n-1],s2[i]);
                 v.pb({n,i+1});

                 break;

             }
         }

     }
 }
 if(s1==s2&&v.size()<=2*n) {
        cout<<"Yes\n"<<v.size()<<endl;
        for(auto i: v)
            cout<<i.F<<" "<<i.S<<endl;
 }
 else cout<<"No"<<endl;


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t=1;
cin>>t;

   while(t--)
   {
       solve();
   }

}
