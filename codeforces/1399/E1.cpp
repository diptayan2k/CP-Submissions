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

vector<ll> v[200001];
ll n;
ll s;
map<pair<ll, ll>, ll > mp;
ll wt[200001];
ll leaf[200001];

void dfs(ll u, ll par)
{
	wt[u] = mp[ {par, u}];

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs(i, u);
	}
}

void dfs1(ll u, ll par)
{
	leaf[u] = 0;
	ll cnt = 0;

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs1(i, u);
		cnt++;
		leaf[u] += leaf[i];
	}

	if (cnt == 0) leaf[u] = 1;
}


void solve(int t)
{
	cin >> n >> s;

	for (int i = 1; i <= n; i++)
	{
		v[i].clear();
	}


	for (int i = 1; i < n; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		v[x].pb(y);
		v[y].pb(x);
		mp[ {x, y}] = w;
		mp[ {y, x}] = w;
	}

	mp[ {0, 1}] = 0;

	dfs(1, 0);
	dfs1(1, 0);

	set<pair<ll, ll> > st;
	ll sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += wt[i] * leaf[i];
		st.insert({(wt[i] - (wt[i] / 2))*leaf[i], i});
	}

	ll ans = 0;
	while (sum > s)
	{
		auto it = st.end();
		it--;
		pair<ll, ll> d = *it;
		//st.delete(it);
		ll diff = (*it).F;
		ll node = (*it).S;
		ll cnt = leaf[node];

		wt[node] /= 2;
		sum -= diff;
		st.erase(it);
		st.insert({(wt[node] - (wt[node] / 2))*leaf[node], node});
		ans++;

	}

	cout << ans << endl;






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