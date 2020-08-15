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
const int N = 18;

vector<ll> v[101];
bool vis[101];
ll a = INF;
ll b = -1;
pair<ll, ll> p[101];

void dfs(ll u)
{
	vis[u] = true;
	a = min(a, p[u].F);
	b = max(b, p[u].S);

	for (auto i : v[u])
	{
		if (vis[i]) continue;
		dfs(i);
	}
}

void solve(int t)
{
	ll n, m, x;
	cin >> n >> x >> m;
	a = INF;
	b = -1;

	for (int i = 0; i < m; i++)
	{
		vis[i] = false;
		v[i].clear();
	}

	ll flag = 0;


	for (int i = 0; i < m; i++)
	{
		cin >> p[i].F >> p[i].S;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (!(p[i].F > p[j].S or p[i].S < p[j].F))
			{
				v[i].pb(j);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (!vis[i] and p[i].F <= x and p[i].S >= x)
		{
			flag = 1;
			dfs(i);
		}
	}

	//cout << a << " " << b << endl;

	if (flag == 0)
	{
		cout << 1 << endl;
		return;
	}
	cout << b - a + 1 << endl;
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