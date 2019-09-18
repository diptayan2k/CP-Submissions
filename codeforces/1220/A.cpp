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
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;
pq<ll> pp;




void dfs(vv<ll> v[],bool vis[],ll i)
{
      vis[i]=true;
    cout<<i<<" ";
    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs(v,vis,v[i][j]);

    }

}


void bfs(vv<ll> v[],bool vis[],ll i)
{
    queue<ll> q;

    q.push(i);
    vis[i] = true;

    while(!q.empty()) {

        ll i = q.front();
        q.pop();

        cout << i << " ";


        f(j,0,v[i].size()-1){
            if (!vis[v[i][j]]) {
                q.push(v[i][j]);
                vis[v[i][j]] = true;
            }
        }
    }

}


ll N = 1000001;  // limit for array size
ll n;  // array size
ll t[2000002];

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(ll l, ll r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main()
{
 ll n;
 cin>>n;
 string s;
 cin>>s;
 ll a=0;
 ll b=0;
 f(i,0,n-1) if(s[i]=='z') a++;
 f(i,0,n-1) if(s[i]=='n') b++;
 f(i,1,b) cout<<1<<" ";
 f(i,1,a) cout<<0<<" ";
}

