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

ll n, m;
ll lvl[2001][2001];
string s[2001];
bool vis[2001][2001];



void solve(int t)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> s[i];

	memset(vis, false, sizeof(vis));

	for (int ch = 'a'; ch <= 'z'; ch++)
	{
		queue<pair<ll, ll> > q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == ch)
				{
					if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
					{
						q.push({i, j});
						lvl[i][j] = 1;
						vis[i][j] = true;
					}
					else if (s[i - 1][j] != ch or s[i + 1][j] != ch or s[i][j - 1] != ch or s[i][j + 1] != ch)
					{
						q.push({i, j});
						lvl[i][j] = 1;
						vis[i][j] = true;
					}
				}
			}
		}

		while (!q.empty())
		{
			ll x = q.front().F;
			ll y = q.front().S;
			q.pop();

			if (x > 0 and s[x - 1][y] == ch and !vis[x - 1][y])
			{
				q.push({x - 1, y});
				vis[x - 1][y] = true;
				lvl[x - 1][y] = lvl[x][y] + 1;
			}

			if (y > 0 and s[x][y - 1] == ch and !vis[x][y - 1])
			{
				q.push({x, y - 1});
				vis[x][y - 1] = true;
				lvl[x][y - 1] = lvl[x][y] + 1;
			}

			if (x < n - 1 and s[x + 1][y] == ch and !vis[x + 1][y])
			{
				q.push({x + 1, y});
				vis[x + 1][y] = true;
				lvl[x + 1][y] = lvl[x][y] + 1;
			}

			if (y < m - 1 and s[x][y + 1] == ch and !vis[x][y + 1])
			{
				q.push({x, y + 1});
				vis[x][y + 1] = true;
				lvl[x][y + 1] = lvl[x][y] + 1;
			}


		}
	}

	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << lvl[i][j] << " ";
			sum += lvl[i][j];
		}
		//cout << endl;
	}

	cout << sum << endl;




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