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

vector<ll> v[100001];
ll par[100001][21];
ll lev[100001];
ll in[100001], out[100001];
ll subtr[100001];
ll T = 0;

void dfs(ll u, ll parent)
{

	par[u][0] = parent;
	subtr[u] = 1;
	for (auto i : v[u])
	{
		if (i == parent) continue;
		lev[i] = lev[u] + 1;
		dfs(i, u);
		subtr[u] += subtr[i];
	}

}

ll kthparent(ll x, ll y)
{
	for (ll i = 20; i >= 0; i--)
	{
		if (y >= (1ll << i))
			x = par[x][i], y -= (1ll << i);
	}
	return x;
}




ll lca(ll x, ll y)
{
	if (lev[x] < lev[y])
		swap(x, y);
	for (ll i = 20; i >= 0; i--)
	{
		if (lev[x] - (1ll << i) >= lev[y])
			x = par[x][i];
	}
	if (x == y)
		return x;
	for (ll i = 20; i >= 0; i--)
	{
		if (par[x][i] != par[y][i])
			x = par[x][i], y = par[y][i];
	}
	return par[x][0];


}


void solve(int t)
{

	ll n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}



	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			par[i][j] = -1;
		}
	}

	lev[1] = 0;
	dfs(1, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			if (par[i][j - 1] != 0)
			{

				ll u = par[i][j - 1];
				if (u != -1)
					par[i][j] = par[u][j - 1];
			}
		}
	}

	ll q;
	cin >> q;
	while (q--)
	{

		
		ll x, y;
		cin >> x >> y;
		if (lev[y] > lev[x]) swap(x, y);
		ll p = lca(x, y);
		ll dis = lev[x] + lev[y] - 2 * lev[p];

		if (x == y)
		{
			cout << n << endl;
			continue;
		}
		if (dis % 2 == 1)
		{
			cout << "0" << endl;
			continue;
		}
		if (lev[x] == lev[y])
		{
			ll ans = n;
			ll dif = abs(lev[p] - lev[x]);
			ans -= subtr[kthparent(x, dif - 1)];
			ans -= subtr[kthparent(y, dif - 1)];
			cout << ans << endl;
			continue;
		}


		p = kthparent(x, dis / 2);
		ll q = kthparent(x, dis / 2 - 1);

		cout << subtr[p] - subtr[q] << endl;
		









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