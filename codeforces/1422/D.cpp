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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


vector<pair<ll, ll> > v[200001];
ll dis[200001];

bool cmp(pair<ll, ll> p, pair<ll, ll> q)
{
	if (p.S == q.S) return p.F < q.F;
	return p.S < q.S;
}

void dijkstra(ll src, ll n)
{
	for (ll i = 1; i <= n; i++) dis[i] = INF;
	dis[src] = 0;
	set<pair<ll, ll> > st;
	st.insert({0, src});

	while (!st.empty())
	{
		pair<ll, ll> tmp = *(st.begin());
		ll p = tmp.S;
		st.erase(st.begin());
		for (auto i : v[tmp.S])
		{
			ll u = i.F;
			ll wt = i.S;
			if (dis[u] > dis[p] + wt)
			{
				if (dis[u] != INF)
				{
					st.erase(st.find({dis[u], u}));
				}
				dis[u] = dis[p] + wt;
				st.insert({dis[u], u});


			}

		}
	}
}

void solve(int t)
{

	ll n, m;
	cin >> n >> m;
	ll sx, sy, fx, fy;
	cin >> sx >> sy >> fx >> fy;

	ll x[m], y[m];

	for (int i = 0; i < m; i++)
	{
		cin >> x[i] >> y[i];
	}

	map<pair<ll, ll>, ll> mp;

	ll k  = 0;
	for (int  i = 0; i < m; i++)
	{
		if (mp[ {x[i], y[i]}] == 0)
		{
			mp[ {x[i], y[i]}] = ++k;
		}
	}

	vector<pair<ll, ll> > cordinate;

	for (auto i : mp)
	{
		cordinate.push_back(i.F);
	}

	sort(cordinate.begin(), cordinate.end());

	for (int i = 0; i < cordinate.size(); i++)
	{
		if (i > 0)
		{
			ll dist = min(abs(cordinate[i].F - cordinate[i - 1].F), abs(cordinate[i].S - cordinate[i - 1].S));
			ll idx1 = mp[cordinate[i]];
			ll idx2 = mp[cordinate[i - 1]];

			v[idx1].pb({idx2, dist});
			v[idx2].pb({idx1, dist});

		}
		if (i < cordinate.size() - 1)
		{
			ll dist = min(abs(cordinate[i].F - cordinate[i + 1].F), abs(cordinate[i].S - cordinate[i + 1].S));
			ll idx1 = mp[cordinate[i]];
			ll idx2 = mp[cordinate[i + 1]];

			v[idx1].pb({idx2, dist});
			v[idx2].pb({idx1, dist});

		}
	}

	sort(cordinate.begin(), cordinate.end(), cmp);

	for (int i = 0; i < cordinate.size(); i++)
	{
		if (i > 0)
		{
			ll dist = min(abs(cordinate[i].F - cordinate[i - 1].F), abs(cordinate[i].S - cordinate[i - 1].S));
			ll idx1 = mp[cordinate[i]];
			ll idx2 = mp[cordinate[i - 1]];

			v[idx1].pb({idx2, dist});
			v[idx2].pb({idx1, dist});
		}
		if (i < cordinate.size() - 1)
		{
			ll dist = min(abs(cordinate[i].F - cordinate[i + 1].F), abs(cordinate[i].S - cordinate[i + 1].S));
			ll idx1 = mp[cordinate[i]];
			ll idx2 = mp[cordinate[i + 1]];

			v[idx1].pb({idx2, dist});
			v[idx2].pb({idx1, dist});
		}
	}

	if (mp[ {sx, sy}] == 0) mp[ {sx, sy}] = ++k;
	if (mp[ {fx, fy}] == 0) mp[ {fx, fy}] = ++k;


	for (auto i : cordinate)
	{
		pair<ll, ll> p = i;
		ll dist = min(abs(i.F - sx), abs(i.S - sy));
		ll idx1 = mp[i];
		ll idx2 = mp[ {sx, sy}];

		v[idx1].pb({idx2, dist});
		v[idx2].pb({idx1, dist});

	}

	for (auto i : cordinate)
	{
		pair<ll, ll> p = i;
		ll dist = (abs(i.F - fx) + abs(i.S - fy));
		if (mp[ {fx, fy}] < k) dist = min(abs(i.F - fx), abs(i.S - fy));
		ll idx1 = mp[i];
		ll idx2 = mp[ {fx, fy}];

		v[idx1].pb({idx2, dist});
		v[idx2].pb({idx1, dist});

	}

	dijkstra(mp[ {sx, sy}], k);
	ll ans = abs(sx - fx) + abs(sy - fy);
	cout << min(ans, dis[mp[ {fx, fy}]]) << endl;







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