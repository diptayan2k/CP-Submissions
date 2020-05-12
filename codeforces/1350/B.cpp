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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
ll mod = 1e9 + 7;
ll INF = 1000000000000000000;
vector<ll> v[100001];

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll dp[n + 1];
	dp[1] = 1;
	for (int i = 2; i <= n; i++) dp[i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (auto j : v[i])
		{
			if (a[j] < a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
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

	for (int i = 2; i <= 100000; i++)
	{
		v[i].pb(1);
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				v[i].pb(j);
				v[i].pb(i / j);
			}
		}

	}



	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}