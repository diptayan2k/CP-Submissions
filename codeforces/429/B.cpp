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


void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	ll a[n + 1][m + 1];
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	ll dp1[n + 2][m + 2];
	ll dp2[n + 2][m + 2];
	ll dp3[n + 2][m + 2];
	ll dp4[n + 2][m + 2];

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			dp1[i][j] = 0;
			dp2[i][j] = 0;
			dp3[i][j] = 0;
			dp4[i][j] = 0;
		}
	}


	for (int i = n; i > 0; i--)
	{
		for (int j = m; j > 0; j--)
		{
			dp1[i][j] = a[i][j] + max(dp1[i + 1][j], dp1[i][j + 1]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j - 1]);
		}
	}

	for (int i = n; i > 0; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			dp3[i][j] = a[i][j] + max(dp3[i][j - 1], dp3[i + 1][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i - 1][j]);
		}
	}

	ll ans = 0;

	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			ans = max(dp1[i + 1][j] + dp2[i - 1][j] + dp3[i][j - 1] + dp4[i][j + 1], ans);
			ans = max(dp1[i][j + 1] + dp2[i][j - 1] + dp3[i + 1][j] + dp4[i - 1][j], ans);
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