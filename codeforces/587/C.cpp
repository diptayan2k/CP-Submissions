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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

vector<ll> adj[100001];
vector<ll> id[100001], dp[100001][21];
vector<vector<ll> > par(100001, vector<ll>(21, -1));
ll lev[100001];

ll kthanc(ll x, ll k)
{

	for (int i = 20; i >= 0; i--)
	{
		if (((1ll << i)&k) != 0) x = par[x][i];
	}

	return x;
}

ll lca(ll x, ll y)
{
	if (lev[x] < lev[y]) swap(x, y);
	ll diff = abs(lev[x] - lev[y]);
	x = kthanc(x, diff);

	if (x == y) return x;

	for (int i = 20; i >= 0; i--)
	{
		if (par[x][i] != -1 and par[x][i] != par[y][i])
		{
			x = par[x][i];
			y = par[y][i];
		}
	}


	return par[x][0];

}

vector<ll> merg(vector<ll> p, vector<ll> q)
{
	vector<ll> ans;
	ll i = 0;
	ll j = 0;

	while (i < p.size() and j < q.size() and ans.size() < 10)
	{
		if (p[i] < q[j])
		{
			if (!ans.empty() and ans[ans.size() - 1] == p[i]) i++;
			else ans.pb(p[i++]);
		}
		else
		{
			if (!ans.empty() and ans[ans.size() - 1] == q[j]) j++;
			else ans.pb(q[j++]);
		}
	}

	while (i < p.size() and ans.size() < 10)
	{
		if (!ans.empty() and ans[ans.size() - 1] == p[i]) i++;
		else ans.pb(p[i++]);
	}

	while (j < q.size() and ans.size() < 10)
	{
		if (!ans.empty() and ans[ans.size() - 1] == q[j]) j++;
		else ans.pb(q[j++]);
	}

	return ans;
}

void dfs(ll u, ll p)
{

	par[u][0] = p;
	dp[u][0] = merg(id[u], id[p]);

	for (auto i : adj[u])
	{
		if (i == p) continue;
		lev[i] = lev[u] + 1;
		dfs(i, u);
	}

}

void solve(int t)
{

	ll n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < n - 1; i++)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		if (id[x].size() < 10)
			id[x].pb(i + 1);
	}

	lev[1] = 0;
	dfs(1, 0);
	par[1][0] = -1;

	for (int j = 1; j <= 20; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			ll u = par[i][j - 1];

			if (u != -1)
			{
				par[i][j] = par[u][j - 1];

				dp[i][j] = merg(dp[u][j - 1], dp[i][j - 1]);
			}
		}
	}




	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			cout << par[i][j] << " ";
		}
		cout << endl;
	}*/
	/*
	for (auto i : dp[8][0])
	{
		cout << i << " ";
	}


	cout << endl;
	cout << kthanc(4, 3) << endl;


	cout << endl;*/
	while (q--)
	{
		ll x, y, a;

		cin >> x >> y >> a;

		if (lev[x] < lev[y]) swap(x, y);

		ll anc = lca(x, y);

		vector<ll> ans1 = id[x];
		ll diff = abs(lev[anc] - lev[x]);

		ll p = x;
		ll q = y;

		for (int i = 20; i >= 0; i--)
		{
			if (((1ll << i)&diff) != 0)
			{
				ans1 = merg(ans1, dp[p][i]);
				p = par[p][i];
			}
		}

		diff = abs(lev[anc] - lev[y]);

		vector < ll > ans2 = id[y];

		p = y;
		for (int i = 20; i >= 0 ; i--)
		{
			if (((1ll << i)&diff) != 0)
			{
				ans2 = merg(ans2, dp[p][i]);
				p = par[p][i];
			}
		}


		vector<ll> ans = merg(ans1, ans2);
		//ans = merg(ans, id[anc]);

		cout << min((ll)ans.size(), a) << " ";
		for (int i = 0; i < min((ll)ans.size(), a); i++) cout << ans[i] << " ";
		cout << endl;
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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}