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

ll power(ll x, ll y)
{
	if (y == 0) return 1;
	ll q = power(x, y / 2) % mod;
	if (y % 2 == 0)
		return (q * q) % mod;
	else
		return ((q * q) % mod * x) % mod;
}

set<ll> v[21];
bool vis[21];


ll cn;
void dfs(ll u)
{

	vis[u] = true;
	cn++;

	for (auto i : v[u])
	{

		if (vis[i]) continue;
		dfs(i);
	}

}



void solve(int t)
{
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < n; i++)
	{
		if (b[i] < a[i])
		{
			cout << -1 << endl;
			return;
		}
	}
	map<ll, ll> m;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i]) continue;
		v[a[i] - 'a'].insert(b[i] - 'a');
		v[b[i] - 'a'].insert(a[i] - 'a');
		m[b[i] - 'a']++;
	}

	memset(vis, false, sizeof(vis));

	ll ans = 0;
	for (int i = 0; i < 21; i++)
	{
		cn = 0;

		if (m[i] == 0 and !v[i].empty())
		{

			dfs(i);

			ans += (cn - 1);
		}

		//cout << cn << " ";



	}
	//cout << endl;

	cout << ans << endl;

	for (int i = 0; i < 21; i++) v[i].clear();










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