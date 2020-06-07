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
const int N = 21;

void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'B')
			{
				if (j < m - 1 and s[i][j + 1] == '.')
				{
					s[i][j + 1] = '#';
				}
				if (i < n - 1 and s[i + 1][j] == '.')
				{
					s[i + 1][j] = '#';
				}
				if (j > 0 and s[i][j - 1] == '.')
				{
					s[i][j - 1] = '#';
				}
				if (i > 0 and s[i - 1][j] == '.')
				{
					s[i - 1][j] = '#';
				}

			}
		}
	}

	ll a[n][m];
	memset(a, 0, sizeof(a));


	queue<pair<ll, ll>> q;
	if (s[n - 1][m - 1] != '#')
	{
		q.push({n - 1, m - 1});
		a[n - 1][m - 1] = 1;

	}
	while (!q.empty())
	{
		pair<ll, ll> p = q.front();
		q.pop();
		ll x = p.F;
		ll y = p.S;
		if (x < n - 1 and  a[x + 1][y] == 0 and s[x + 1][y] != '#')
		{
			a[x + 1][y] = 1;
			q.push({x + 1, y});
		}
		if (y < m - 1 and  a[x][y + 1] == 0 and s[x][y + 1] != '#')
		{
			a[x][y + 1] = 1;
			q.push({x, y + 1});
		}
		if (x > 0 and  a[x - 1][y] == 0 and s[x - 1][y] != '#')
		{
			a[x - 1][y] = 1;
			q.push({x - 1, y});
		}
		if (y > 0 and  a[x][y - 1] == 0 and s[x][y - 1] != '#')
		{
			a[x][y - 1] = 1;
			q.push({x, y - 1});
		}

	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'B' and a[i][j] == 1)
			{
				cout << "No" << endl;
				return;
			}
			if (s[i][j] == 'G' and a[i][j] == 0)
			{
				cout << "No" << endl;
				return;
			}
		}
	}

	cout << "Yes" << endl;

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