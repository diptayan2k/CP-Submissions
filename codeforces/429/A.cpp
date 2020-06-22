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

ll n;
vector<ll> v[100001];
ll a[100001], goal[100001];
ll cnt = 0;
vector<ll> ans;
ll lvl[100001] = {0};

void dfs(ll u, ll par)
{
	lvl[u] = lvl[par] + 1;

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs(i, u);
	}
}

void dfs1(ll u, ll par, ll odd , ll even)
{
	if (lvl[u] % 2 == 0)
	{
		a[u] ^= even;
		if (a[u] != goal[u])
		{
			even ^= 1;
			cnt++;
			ans.pb(u);
		}
	}
	else
	{
		a[u] ^= odd;
		if (a[u] != goal[u])
		{
			odd ^= 1;
			cnt++;
			ans.pb(u);
		}
	}

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs1(i, u, odd, even);
	}

}



void solve(int t)
{

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> goal[i];
	lvl[0] = -1;
	dfs(1, 0);
	//for (int i = 1; i <= n; i++) cout << i << " " << lvl[i] << " " << endl;
	dfs1(1, 0, 0, 0);


	cout << cnt << endl;
	for (auto i : ans) cout << i << endl;

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