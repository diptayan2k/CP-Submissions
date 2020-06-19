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
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

vector<ll> v[101];
bool vis[100];
ll n;

void dfs(ll u)
{
	vis[u] = true;

	for (auto i : v[u])
	{
		if (vis[i]) continue;
		dfs(i);
	}

}

void solve(int t)
{
	cin >> n;
	ll x[n], y[n];

	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] == x[j] or y[i] == y[j])
			{
				v[i].pb(j);
				v[j].pb(i);
			}
		}
	}

	memset(vis, false, sizeof(vis));

	ll cn = 0;

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			cn++;
		}
	}
	cout << cn - 1 << endl;


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