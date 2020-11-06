#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> adj[100001];
ll dp[100001][21];
ll n;
ll lvl[100001];
ll sub[100001];
ll t=0;

void dfs(ll x,ll par)
{
	dp[x][0]=par;
	sub[x]=1;
	for(auto i:adj[x])
	{
		if(i==par) continue;
		lvl[i]=lvl[x]+1;
		dfs(i,x);
		sub[x]+=sub[i];
	}
}

ll lca(ll x,ll y)
{
	if(lvl[x]<lvl[y])
	swap(x,y);
	for(ll i=20;i>=0;i--)
	{
		if(lvl[x]-(1ll<<i)>=lvl[y])
		x=dp[x][i];
	}
	if(x==y)
	return x;
	for(ll i=20;i>=0;i--)
	{
		if(dp[x][i]!=dp[y][i])
		x=dp[x][i],y=dp[y][i];
	}
	return dp[x][0];
}

ll parent(ll x,ll y)
{
	for(ll i=20;i>=0;i--)
	{
		if(y>=(1ll<<i))
		x=dp[x][i],y-=(1ll<<i);
	}
	return x;
}

int main()
{
	ll i,j,k,m;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>j>>k;
		j--;k--;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	lvl[0]=0;
	dfs(0,0);
	
	for(j=1;j<=20;j++)
	{
		for(i=0;i<n;i++)
		{
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	ll test;
	cin>>test;
	while(test--)
	{
		cin>>j>>k;
		j--,k--;
		if(j==k)
		cout<<n<<'\n';
		else
		{
			ll l=lca(j,k);
			if(lvl[j]-lvl[l]==lvl[k]-lvl[l])
			{
				ll ans=n;
				ll diff=lvl[j]-lvl[l]-1;
				ll x=parent(j,diff);
				ans-=sub[x];
				x=parent(k,diff);
				ans-=sub[x];
				cout<<ans<<"\n";
			}
			else
			{
				ll dist=lvl[j]+lvl[k]-2*lvl[l];
				if(dist%2==1)
				cout<<0<<'\n';
				else
				{
					if(lvl[j]<lvl[k])
					swap(j,k);
					ll x=parent(j,dist/2);
					ll p1=parent(j,dist/2-1);
					ll ans=sub[x]-sub[p1];
					cout<<ans<<'\n';
				}
			}
		}
	}
}