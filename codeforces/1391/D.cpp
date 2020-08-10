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

ll  dp[1000001][2][2][2];
ll dp1[1000001][2][2];
ll mat[1000001][3];
string s[1001];
ll m;

ll foo(ll idx, ll a, ll b , ll c)
{
	if (idx == m)
	{
		return 0;
	}

	ll res = INF;

	if (dp[idx][a][b][c] != -1) return dp[idx][a][b][c];

	if (b == 0)
	{
		res = min((mat[idx][0] != a) + (mat[idx][1] != 1) + (mat[idx][2] != c) + foo(idx + 1, a, 1, c), res);
		res = min((mat[idx][0] == a) + (mat[idx][1] != 0) + (mat[idx][2] == c) + foo(idx + 1, a ^ 1, 0, c ^ 1), res);
	}
	else if (b == 1)
	{
		res = min(res, (mat[idx][0] == a) + (mat[idx][1] != 1) + (mat[idx][2] == c) + foo(idx + 1, a ^ 1, 1, c ^ 1));
		res = min(res, (mat[idx][0] != a) + (mat[idx][1] != 0) + (mat[idx][2] != c) + foo(idx + 1, a, 0, c));
	}

	return dp[idx][a][b][c] = res;
}


ll foo1(ll idx, ll a, ll b)
{
	if (idx == m)
	{
		return 0;
	}

	ll res = INF;
	if (dp1[idx][a][b] != -1) return dp1[idx][a][b];

	if (b == 0)
	{
		res = min((mat[idx][0] != a) + (mat[idx][1] != 1) + foo1(idx + 1, a, 1), res);
		res = min((mat[idx][0] == a) + (mat[idx][1] != 0) + foo1(idx + 1, a ^ 1, 0), res);
	}
	else if (b == 1)
	{
		res = min(res, (mat[idx][0] == a) + (mat[idx][1] != 1)  + foo1(idx + 1, a ^ 1, 1));
		res = min(res, (mat[idx][0] != a) + (mat[idx][1] != 0)  + foo1(idx + 1, a, 0));
	}

	return dp1[idx][a][b] = res;
}


void solve(int t)
{
	ll n;
	cin >> n >> m;
	if (n > 3)
	{
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[j][i] = s[i][j] - '0';
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				dp1[i][j][k] = -1;
				for (int l = 0; l < 2; l++)
				{
					dp[i][j][k][l] = -1;
				}
			}
		}
	}

	ll ans = INF;

	if (n == 1)
	{
		cout << 0 << endl;
		return;
	}

	if (n == 2)
	{
		ans = min(ans, foo1(1, 0, 0) + (mat[0][0] != 0) + (mat[0][1] != 0) );
		ans = min(ans, foo1(1, 0, 1) + (mat[0][0] != 0) + (mat[0][1] != 1) );
		ans = min(ans, foo1(1, 1, 0) + (mat[0][0] != 1) + (mat[0][1] != 0) );
		ans = min(ans, foo1(1, 1, 1) + (mat[0][0] != 1) + (mat[0][1] != 1) );


	}


	if (n == 3)
	{

		ans = min(ans, foo(1, 0, 0, 0) + (mat[0][0] != 0) + (mat[0][1] != 0) + (mat[0][2] != 0));
		ans = min(ans, foo(1, 0, 0, 1) + (mat[0][0] != 0) + (mat[0][1] != 0) + (mat[0][2] != 1));
		ans = min(ans, foo(1, 0, 1, 0) + (mat[0][0] != 0) + (mat[0][1] != 1) + (mat[0][2] != 0));
		ans = min(ans, foo(1, 0, 1, 1) + (mat[0][0] != 0) + (mat[0][1] != 1) + (mat[0][2] != 1));
		ans = min(ans, foo(1, 1, 0, 0) + (mat[0][0] != 1) + (mat[0][1] != 0) + (mat[0][2] != 0));
		ans = min(ans, foo(1, 1, 0, 1) + (mat[0][0] != 1) + (mat[0][1] != 0) + (mat[0][2] != 1));
		ans = min(ans, foo(1, 1, 1, 0) + (mat[0][0] != 1) + (mat[0][1] != 1) + (mat[0][2] != 0));
		ans = min(ans, foo(1, 1, 1, 1) + (mat[0][0] != 1) + (mat[0][1] != 1) + (mat[0][2] != 1));
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