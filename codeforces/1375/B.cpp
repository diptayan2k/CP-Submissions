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
const int d = (1ll << N);
ll F[d];



void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	ll ans[n][m];
	ll a[n][m];



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (i == 0 and j == 0) ans[i][j] = 2;
			else if (i == 0 and j == m - 1) ans[i][j] = 2;
			else if (i == n - 1 and j == 0) ans[i][j] = 2;
			else if (i == n - 1 and j == m - 1) ans[i][j] = 2;
			else if (i == 0) ans[i][j] = 3;
			else if (i == n - 1) ans[i][j] = 3;
			else if (j == 0) ans[i][j] = 3;
			else if (j == m - 1) ans[i][j] = 3;
			else ans[i][j] = 4;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m ; j++)
		{

			if (a[i][j] > ans[i][j])
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
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
	cin >> t;


	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}