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
const int N = 20;

ll n, m;
ll len[2001][2001];
bool vis[2001][2001];
ll k;



void solve(int t)
{
	cin >> n >> m;
	cin >> k;
	vector<pair<ll, ll> > v;

	for (int i = 0; i < k; i++)
	{
		ll x, y;
		cin >> x >> y;
		v.pb({x - 1, y - 1});
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			len[i][j] = INF;
		}
	}
	memset(vis, false, sizeof(vis));

	for (auto i : v)
	{

		len[i.F][i.S] = 0;
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++) vis[j][l] = false;
		}
		queue<pair<ll, ll> > q;
		q.push(i);

		vis[i.F][i.S] = true;

		while (!q.empty())
		{
			pair<ll, ll> u = q.front();
			ll x = u.F;
			ll y = u.S;
			//cout << x << " " << y << " " << len[x][y] << endl; endl;
			q.pop();

			if (x > 0 and !vis[x - 1][y])
			{
				len[x - 1][y] = min(len[x][y] + 1, len[x - 1][y]);
				q.push({x - 1, y});
				vis[x - 1][y] = true;
			}

			if (x < n - 1 and !vis[x + 1][y])
			{
				len[x + 1][y] = min(len[x][y] + 1, len[x + 1][y]);
				q.push({x + 1, y});
				vis[x + 1][y] = true;
			}

			if (y > 0 and !vis[x][y - 1])
			{
				len[x][y - 1] = min(len[x][y] + 1, len[x][y - 1]);
				q.push({x, y - 1});
				vis[x][y - 1] = true;
			}
			if (y < m - 1 and !vis[x][y + 1])
			{
				len[x][y + 1] = min(len[x][y] + 1, len[x][y + 1]);
				q.push({x, y + 1});
				vis[x][y + 1] = true;
			}
		}

	}

	ll ma = -1;
	ll ansx = -1;
	ll ansy = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << len[i][j] << " ";
			if (len[i][j] > ma)
			{
				ma = len[i][j];
				ansx = i + 1;
				ansy = j + 1;
			}
		}
		//cout << endl;


	}

	cout << ansx << " " << ansy << endl;



}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}