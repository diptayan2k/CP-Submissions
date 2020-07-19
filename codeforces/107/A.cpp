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
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

ll n, m;
vector<pair<ll, ll> >  v[1001];
bool vis[1001];

bool dfs(ll u, ll dia)
{
	vis[u] = true;

	if (v[u].empty())
	{
		cout << u << " " << dia << endl;
	}

	for (auto i : v[u])
	{
		if (vis[i.F]) continue;

		dfs(i.F, min(dia, i.S));
	}
}

void solve(int t)
{
	cin >> n >> m;
	map<ll, ll> mm;
	for (int i = 0; i < m; i++)
	{
		ll a, b, d;
		cin >> a >> b >> d;
		v[a].pb({b, d});
		mm[b]++;
	}

	ll tank = 0;
	ll tap = 0;

	for (int i = 1; i <= n; i++)
	{
		if (v[i].empty() and mm[i] > 0)
		{
			tap++;
		}
		if (mm[i] == 0 and !v[i].empty())
		{
			tank++;
		}

	}

	memset(vis, false, sizeof(vis));

	cout << tank << endl;

	for (int i = 1; i <= n; i++)
	{
		if (mm[i] == 0 and !vis[i] and !v[i].empty())
		{
			cout << i << " ";
			dfs(i, INF);
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