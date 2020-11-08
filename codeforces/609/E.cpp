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

vector<ll> v[200001];
vector<pair<ll, ll> > edge;
map<pair<ll, ll>, ll> mp;
vector<vector<ll> > dp(200001, vector<ll>(21, -1)), par(200001, vector<ll>(21, -1));

ll siz[200001];
ll a[200001];
ll lev[200001];
vector<bool> flag(200001, false);

void dfs(ll u, ll p)
{
	lev[u] = lev[p] + 1;
	par[u][0] = p;
	dp[u][0] = mp[ {u, p}];

	for (auto i : v[u])
	{
		if (i == p) continue;
		dfs(i, u);
	}
}

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
	if (lev[y] > lev[x]) swap(x, y);
	x = kthanc(x, lev[x] - lev[y]);

	if (x == y) return x;

	for (int i = 20; i >= 0; i--)
	{
		if (par[x][i] != 0 and par[x][i] != par[y][i])
		{
			x = par[x][i];
			y = par[y][i];
		}
	}

	return par[x][0];

}

ll pathmax(ll x, ll y)
{
	if (lev[y] > lev[x]) swap(x, y);

	ll ma = 0;
	ll k = lev[x] - lev[y];

	for (int i = 20; i >= 0; i--)
	{
		if (((1ll << i)&k) != 0)
		{
			ma = max(ma, dp[x][i]);
			x = par[x][i];
		}
	}

	return ma;

}

void intialise(ll n)
{
	for (int i = 0; i <= n; i++)
	{
		a[i] = i;
		siz[i] = 1;
	}

}

ll root(ll i)
{
	while (a[i] != i)
	{
		a[i] = a[a[i]] ;
		i = a[ i ];
	}
	return i;
}

void union_(ll x, ll y)
{
	ll rootx = root(x);
	ll rooty = root(y);
	if (siz[rooty] > siz[rootx])
	{
		swap(x, y);
		swap(rootx, rooty);
	}
	a[rooty] = rootx;
	siz[rootx] += siz[rooty];

}

bool check_connection(ll x, ll y)
{
	ll rootx = root(x);
	ll rooty = root(y);

	if (rootx == rooty) return true;
	else return false;

}

void solve(int t)
{

	ll n, m;
	cin >> n >> m;

	intialise(n);
	ll sum = 0;

	vector<vector<ll> > pp;

	for (int i = 0; i < m; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		edge.pb({x, y});
		pp.pb({w, i, x, y});
		mp[ {x, y}] = w;
		mp[ {y, x}] = w;


	}

	sort(pp.begin(), pp.end());

	for (int i = 0; i < m; i++)
	{
		ll x = pp[i][2];
		ll y = pp[i][3];
		ll idx = pp[i][1];
		ll w = pp[i][0];

		if (!check_connection(x, y))
		{
			flag[idx] = 1;
			v[x].pb(y);
			v[y].pb(x);
			sum += w;
			union_(x, y);
		}

	}


	lev[0] = -1;
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
				dp[i][j] = max(dp[u][j - 1], dp[i][j - 1]);
			}
		}
	}


	for (int i = 0; i < m; i++)
	{
		ll x = edge[i].F;
		ll y = edge[i].S;
		if (flag[i])
		{
			cout << sum << endl;
		}
		else
		{
			ll anc = lca(x, y);
			ll ans = sum;
			ans += mp[ {x, y}];
			ll d = 0;
			if (x != anc) d = max(d, pathmax(x, anc));
			if (y != anc) d = max(d, pathmax(y, anc));

			ans -= d;
			cout << ans << endl;
		}
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