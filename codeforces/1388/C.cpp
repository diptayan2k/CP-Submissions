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


vector<ll> v[100001];
ll n, m;
ll p[100001];
ll h[100001];
ll subtr[100001];
ll g[100001];
ll b[100001];
ll flag = 0;
ll sum[100001];


ll dfs(ll u, ll par)
{


	subtr[u] = p[u];
	sum[u] = h[u];

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs(i, u);
		subtr[u] += subtr[i];
		sum[u] += sum[i];
	}


}

ll dfs1(ll u, ll par)
{
	ll ss = 0;

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs1(i, u);
		ss += g[i];

	}

	if (ss > g[u]) flag = 1;


}




void solve(int t)
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		v[i].clear();
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}

	for (int i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);

	}




	dfs(1, 0);



	for (int i = 1; i <= n; i++)
	{
		ll d = subtr[i] + h[i];
		ll e = subtr[i] - h[i];


		if (h[i] < -1 * subtr[i] or h[i] > subtr[i])
		{
			cout << "NO" << endl;
			return;
		}

		if (d % 2 == 1 or e % 2 == 1)
		{
			cout << "NO" << endl;
			return;
		}
		g[i] = d / 2;
		b[i] = e / 2;
		//cout << g[i] << " " << b[i] << endl;
		if (g[i] < 0 or b[i] < 0)
		{
			cout << "NO" << endl;
			return;
		}

	}

	flag = 0;
	g[0] = INF;
	sum[0] = -INF;

	dfs1(1, 0);

	if (flag)
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;






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