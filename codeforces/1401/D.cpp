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
const int N = 18;


void dfs(ll subtr[], vector<ll> v[], ll u, ll par)
{
	subtr[u] = 1;
	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs(subtr, v, i, u);
		subtr[u] += subtr[i];
	}
}


void solve(int t)
{
	ll n;
	cin >> n;
	vector<ll> v[n + 1];

	vector<pair<ll, ll> > ed;

	for (int i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
		ed.pb({x, y});
	}

	ll subtr[n + 1] = {0};

	dfs(subtr, v, 1, 0);

	ll m;
	cin >> m;
	vector<ll> p;

	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		p.pb(x);
	}

	sort(p.begin(), p.end(), greater<ll>());

	vector<ll> edge;

	for (auto i : ed)
	{
		ll x = i.F;
		ll y = i.S;
		ll z = min(subtr[x], subtr[y]);

		edge.pb(z * (n - z));
	}



	sort(edge.begin(), edge.end(), greater<ll>());

	while (p.size() < edge.size())
	{
		p.pb(1);
	}

	if (p.size() > edge.size())
	{
		vector<ll> q = p;

		reverse(q.begin(), q.end());

		while (q.size() != edge.size())
		{
			ll x = q.back();
			q.pop_back();
			q[q.size() - 1] = (x * q[q.size() - 1]) % mod;
		}

		reverse(q.begin(), q.end());
		p = q;
	}

	ll ans = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		//cout << edge[i] << " " << p[i] << " " << endl;
		ans = (ans + (edge[i] * p[i]) % mod) % mod;
	}

	cout << ans % mod << endl;






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