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

ll n, m, k;
string s[501];
bool vis[501][501];

void solve(int t)
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	pair<ll, ll> p = { -1, -1};
	ll num = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				p = {i, j};
				num++;
			}
		}
	}

	queue<pair<ll, ll> > q;

	q.push(p);
	vis[p.F][p.S] =	true;
	ll cnt = 1;

	if (cnt == num - k)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!vis[i][j] and s[i][j] != '#')
				{
					s[i][j] = 'X';
				}
				cout << s[i][j];
			}
			cout << endl;
		}
		return;

	}

	while (!q.empty())
	{
		pair<ll, ll> u = q.front();
		q.pop();
		ll x = u.F;
		ll y = u.S;

		if (x > 0 and s[x - 1][y] == '.' and !vis[x - 1][y])
		{
			q.push({x - 1, y});
			vis[x - 1][y] = true;
			cnt++;
		}

		if (cnt == num - k)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!vis[i][j] and s[i][j] != '#')
					{
						s[i][j] = 'X';
					}
					cout << s[i][j];
				}
				cout << endl;
			}
			return;

		}

		if (x < n - 1 and s[x + 1][y] == '.' and !vis[x + 1][y])
		{
			q.push({x + 1, y});
			vis[x + 1][y] = true;
			cnt++;
		}

		if (cnt == num - k)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!vis[i][j] and s[i][j] != '#')
					{
						s[i][j] = 'X';
					}
					cout << s[i][j];
				}
				cout << endl;
			}
			return;

		}



		if (y > 0 and s[x][y - 1] == '.' and !vis[x][y - 1])
		{
			q.push({x, y - 1});
			vis[x][y - 1] = true;
			cnt++;
		}

		if (cnt == num - k)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!vis[i][j] and s[i][j] != '#')
					{
						s[i][j] = 'X';
					}
					cout << s[i][j];
				}
				cout << endl;
			}
			return;

		}

		if (y < m - 1 and s[x][y + 1] == '.' and !vis[x][y + 1])
		{
			q.push({x, y + 1});
			vis[x][y + 1] = true;
			cnt++;
		}

		if (cnt == num - k)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!vis[i][j] and s[i][j] != '#')
					{
						s[i][j] = 'X';
					}
					cout << s[i][j];
				}
				cout << endl;
			}
			return;

		}

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
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}