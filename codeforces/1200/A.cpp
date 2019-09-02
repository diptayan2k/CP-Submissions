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
ll n;
cin>>n;
string s;
cin>>s;
ll a[10]={0};
ll p=0;
ll q=9-1;
f(i,0,s.length()-1)
{
    if(s[i]=='L') {f(j,0,9) if(a[j]==0) {a[j]=1; break;}}
    else if(s[i]=='R') {g(j,9,0) if(a[j]==0) {a[j]=1; break;}}
    else a[s[i]-'0']=0;

}

f(i,0,9) cout<<a[i];





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










