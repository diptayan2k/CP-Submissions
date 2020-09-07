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
#define MAX 5

ll n, a, b, da, db;
ll dis[100001];
vector<ll> v[100001];
ll dia = 0;

ll dfs(ll u, ll par)
{

	dis[u] = dis[par] + 1;

	ll x = 0;

	for (auto i : v[u])
	{
		if (i == par) continue;
		ll len = 1+dfs(i, u);
		dia = max(dia, x + len);
		x = max(x, len);
	}


	return x;
}




void solve(int t)
{
	cin >> n >> a >> b >> da >> db;

	for (int i = 0; i <= n; i++)
	{
		v[i].clear();
		dis[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dis[0] = -1;
	dia = 0;
	dfs(b, 0);

	if (2 * da >= min(dia, db) or dis[a] <= da)
	{
		cout << "Alice" << endl;
		return;
	}

	cout << "Bob" << endl;
	return;

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