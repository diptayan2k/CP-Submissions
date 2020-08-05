#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

vector<ll> v[200001], g[200001];
bool vis[200001];
bool rec[200001];
ll n, m;
bool cycle = false;

void check_cycle(ll u)
{
	vis[u] = true;
	rec[u] = true;

	for (auto i : g[u])
	{
		if (rec[i]) cycle = true;
		if (!vis[i])
		{
			check_cycle(i);
		}
	}

	rec[u] = false;
}

stack<ll> st;

void dfs(ll u)
{
	vis[u] = true;

	for (auto i : g[u])
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}

	st.push(u);
}

void solve(int t)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		vis[i] = false;
		v[i].clear();
		g[i].clear();
	}

	map<ll, ll> in;

	vector<pair<ll, ll> > e;

	for (int i = 0; i < m; i++)
	{
		ll c, x, y;
		cin >> c >> x >> y;
		if (c == 0)
		{
			v[x].pb(y);
			v[y].pb(x);
			e.pb({x, y});
		}
		else
		{
			v[x].pb(y);
			g[x].pb(y);
			in[y]++;
			e.pb({x, y});
		}
	}

	cycle = false;

	for (int i = 1 ; i <= n; i++)
	{
		if (!vis[i])
		{
			check_cycle(i);
			if (cycle)
			{
				cout << "NO" << endl;
				return;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		vis[i] = false;
		rec[i] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i]) dfs(i);
		//cout << i << endl;
	}

	/*
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i]) dfs(i);
	}*/

	vector<ll> ans;

	while (!st.empty())
	{
		ans.pb(st.top());
		st.pop();
	}

	map<ll, ll> mp;

	for (int i = 0; i < ans.size(); i++ )
	{
		//cout << ans[i] << " ";
		mp[ans[i]] = i;
	}

	cout << "YES" << endl;

	for (auto i : e)
	{
		ll x = i.F;
		ll y = i.S;
		if (mp[x] > mp[y]) swap(x, y);
		cout << x << " " << y << endl;
	}





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
	cin >> t;


	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}