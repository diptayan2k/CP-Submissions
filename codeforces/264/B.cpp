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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;
ll n;
ll pos[100001];
vector<ll> pr[100001], v[100001];
ll a[100001];
ll dp[100001];

ll foo(ll num)
{
	if (dp[num] != -1) return dp[num];
	ll res = 1;
	for (auto i : v[num])
	{
		res = max(res, 1 + foo(i));
	}
	return dp[num] = res;
}

void solve(int t)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}

	for (int i = 0; i < n; i++)
	{
		ll x = a[i];

		if (x % 2 == 0) pr[2].pb(a[i]);
		while (x % 2 == 0)
		{
			x /= 2;
		}

		for (int j = 3; j * j <= x; j += 2)
		{
			if (x % j == 0)
			{
				pr[j].pb(a[i]);
			}
			while (x % j == 0)
			{
				x /= j;
			}
		}

		if (x > 2)
		{
			pr[x].pb(a[i]);
		}
	}

	for (int i = 1; i <= 100000; i++)
	{
		if (pr[i].size() > 1)
		{
			for (int j = 1; j < pr[i].size(); j++)
			{
				v[pr[i][j - 1]].pb(pr[i][j]);
			}
		}

	}

	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[a[i]] == -1)
		{
			ans = max(ans, foo(a[i]));
		}
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
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}