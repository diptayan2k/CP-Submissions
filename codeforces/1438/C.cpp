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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;




void solve(int t)
{
	ll n, m;
	cin >> n >> m;

	ll a[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	bool vis[n][m];
	memset(vis, false, sizeof(vis));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			queue<pair<ll, ll> > q;
			q.push({i, j});

			while (!q.empty())
			{
				ll x = q.front().F;
				ll y = q.front().S;
				q.pop();

				for (int k = -1; k <= 1; k++)
				{
					if (k == 0) continue;

					if (x + k >= 0 and x + k < n and a[x + k][y] == a[x][y])
					{
						q.push({x + k, y});
						if (!vis[x + k][y])
						{
							a[x + k][y]++;
							vis[x + k][y] = true;
						}
						else
						{
							a[x + k][y]--;
							vis[x + k][y] = false;
						}
					}

					if (y + k >= 0 and y + k < m and a[x][y + k] == a[x][y])
					{
						q.push({x, y + k});
						if (!vis[x][y + k])
						{
							a[x][y + k]++;
							vis[x][y + k] = true;
						}
						else
						{
							a[x][y + k]--;
							vis[x][y + k] = false;
						}
					}

				}

			}

		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	//cout << endl;

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