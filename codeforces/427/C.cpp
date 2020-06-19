#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;
ll n, m;
vector<ll> v[100001], g[100001];
stack<ll> st;
bool vis[100001], vis1[100001];
ll a[100001];
ll mi;
ll sz = 0;

void dfs(ll u)
{
	vis[u] = true;

	for (auto i : v[u])
	{
		if (vis[i]) continue;
		dfs(i);
	}
	st.push(u);
}

void dfs1(ll u)
{
	vis[u] = true;
	mi = min(mi, a[u]);

	for (auto i : g[u])
	{
		if (vis[i]) continue;
		dfs1(i);
	}

}

void dfs2(ll u)
{
	vis1[u] = true;
	if (a[u] == mi) sz++;
	mi = min(mi, a[u]);

	for (auto i : g[u])
	{
		if (vis1[i]) continue;
		dfs2(i);
	}
}

void solve(int t)
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		g[y].pb(x);
	}

	memset(vis, false , sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i]) dfs(i);
	}

	memset(vis, false, sizeof(vis));
	memset(vis, false, sizeof(vis1));
	ll ans = 0;
	ll ways = 1;
	while (!st.empty())
	{
		ll u = st.top();
		//cout << u << " " << endl;
		st.pop();
		mi = INF;
		sz = 0;
		if (!vis[u])
		{
			dfs1(u);
			ans += mi;
			dfs2(u);
			ways = (ways * sz) % mod;
		}
	}

	cout << ans << " " << ways % mod << endl;

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}