#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
#include <iostream>

using namespace std;




int main(){
    ll n;
    cin>>n;
    string s[n];

    f(i,0,n-1) cin>>s[i];

    ll dist[n][n], i, j, k;
    ll graph[n][n];

    f(i,0,n-1) f(j,0,n-1) graph[i][j]=s[i][j]-'0';
      f(i,0,n-1) f(j,0,n-1) if(i!=j&&graph[i][j]==0) graph[i][j]=100000;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];


    for (k = 0; k < n; k++)
    {  for (i = 0; i < n; i++)
        {  for (j = 0; j < n; j++)
            {
                    dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }


  ll m;
  cin>>m;
  ll b[m];
  f(i,0,m-1) cin>>b[i];

  vector<ll> v;
  v.pb(b[0]);
 ll  p=0;
  f(i,2,m-1)
  {
      if(dist[b[p]-1][b[i]-1]!=i-p) {v.pb(b[i-1]); p=i-1;}


  }
  //cout<<dist[1][0]<<" ";
  v.pb(b[m-1]);
  cout<<v.size()<<endl;
  f(i,0,v.size()-1) cout<<v[i]<<" ";

}
