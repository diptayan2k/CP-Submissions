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
using namespace std;
vv<ll> s;
const int MAXN = 1048576;

void dfs(vv<ll> vv[],bool vis[],ll u, ll v)
{  s.pb(u);
   if(u==v) return;
      vis[u]=true;
      if(u==v) return;

   ll ff=0;
    if(!vv[u].empty())
    f(j,0,vv[u].size()-1)
    if(!vis[vv[u][j]])
    {
    dfs(vv,vis,vv[u][j],v);
    ff=1;
    }
    if(ff==0) s.pop_back();



}

void initialize( ll Arr[ ], ll N, ll size[])
{
    for(ll i = 1;i<=N;i++)
    {
Arr[ i ] = i ;
size[ i ] = 1;
}
}

ll root (ll Arr[ ] ,ll i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
i = Arr[ i ];
    }
return i;
}

void unio(ll Arr[ ],ll size[ ],ll A,ll B)
{
    ll root_A = root(Arr,A);
    ll root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];

}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}

}


long long solve(vector<int> &contain)
    {
    	long long ans = 0;
    	for (int j = 0; (1<<j) < MAXN; j++) {
    		for (int i = 0; i < MAXN; i++) if (!(i & (1<<j))) {
    			contain[i] += contain[i^(1<<j)];
    		}
    	}
    	for (int i = 0; i < MAXN; i++) {
    		if (__builtin_popcount(i) & 1) ans -= (contain[i]*1ll*(contain[i]-1));
    		else ans += (contain[i]*1ll*(contain[i]-1));
    	}
    	return ans;
    }
  ll tmain(ll N)
    {

    	vector<int> contain(MAXN);

    	for(int i=0;i<N;i++)
    	{
    		int t;
    		scanf("%d",&t);
    		contain[t]++;
    	}
   return contain[0]+solve(contain);
    }


int main(){
ll t;
cin>>t;
while(t--)
{
ll n,m,k;
cin>>n>>m>>k;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll ff=0;
if(n>1)
f(i,0,n-2)
{
    m+=(a[i]-max(a[i+1]-k,(ll)0));
    if(m<0) ff=1;
}
if(ff) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
}



}

/*
1
6
1 2 3
5 1
5 6
1 3
6 2
6 4
*/










