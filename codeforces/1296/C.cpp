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
  string s;
  cin>>s;
  vector<ll> v[2*n+1];
  ll x=0; ll y=0;
  map< pair<ll,ll>, ll > m;
  m[{0,0}]=1;
  v[1].pb(0);
  ll k=2;
  f(i,0,n-1)
  {
      if(s[i]=='L') x--;
      if(s[i]=='R') x++;
      if(s[i]=='D') y--;
      if(s[i]=='U') y++;

      if(m[{x,y}]==0)
        m[{x,y}]=k++;

      v[m[{x,y}]].pb(i+1);


  }

  vector< pair<ll, pair<ll,ll> > > an;
   ll flag =0;
  f(i,1,2*n)
  {
      if(!v[i].empty()&&v[i].size()>1)
      {
          flag=1;
          sort(v[i].begin(),v[i].end());
          f(j,1,v[i].size()-1)
          {
              an.pb({abs(v[i][j]-v[i][j-1]),{v[i][j-1],v[i][j]}});

          }
      }

  }
  if(an.empty())
  {
      cout<<-1<<endl;
      return;
  }

  sort(an.begin(),an.end());
  cout<<an[0].S.F+1<<" "<<an[0].S.S<<endl;




}

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       solve();
   }

}
