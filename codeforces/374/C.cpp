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
string s[1001];
ll dp[1001][1001];
bool vis[1001][1001];
bool vis1[1001][1001];
map<char, char> mp;
bool cycle = false;

void dfs(ll i, ll j)
{

	vis1[i][j] = true;
	vis[i][j] = true;

	if (i > 0 and s[i - 1][j] == mp[s[i][j]])
	{
		if (!vis[i - 1][j])
		{
			dfs(i - 1, j);
		}
		else if (vis1[i - 1][j])
		{
			cycle  = true;
		}
	}

	if (i < n - 1 and s[i + 1][j] == mp[s[i][j]])
	{
		if (!vis[i + 1][j])
		{
			dfs(i + 1, j);
		}
		else if (vis1[i + 1][j])
		{
			cycle  = true;
		}
	}
	if (j > 0 and s[i][j - 1] == mp[s[i][j]])
	{
		if (!vis[i][j - 1])
		{
			dfs(i, j - 1);
		}
		else if (vis1[i][j - 1])
		{
			cycle  = true;
		}
	}
	if (j < m - 1 and s[i][j + 1] == mp[s[i][j]])
	{
		if (!vis[i][j + 1])
		{
			dfs(i, j + 1);
		}
		else if (vis1[i][j + 1])
		{
			cycle  = true;
		}
	}

	vis1[i][j] = false;

}


ll foo(ll i, ll j)
{

	if (dp[i][j] != -1) return dp[i][j];

	ll res = 0;

	if (i > 0 and s[i - 1][j] == mp[s[i][j]])
	{
		res = max(res, foo(i - 1, j));
	}

	if (i < n - 1 and s[i + 1][j] == mp[s[i][j]])
	{
		res = max(res, foo(i + 1, j));
	}
	if (j > 0 and s[i][j - 1] == mp[s[i][j]])
	{
		res = max(res, foo(i, j - 1));
	}
	if (j < m - 1 and s[i][j + 1] == mp[s[i][j]])
	{
		res = max(res, foo(i, j + 1));
	}

	return dp[i][j] = 1 + res;


}

void solve(int t)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	//memset(dp, 1, sizeof(dp));
	memset(vis1, false, sizeof(vis1));
	memset(vis, false, sizeof(vis));
	mp['D'] = 'I';
	mp['I'] = 'M';
	mp['M'] = 'A';
	mp['A'] = 'D';


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!vis[i][j] and s[i][j] == 'D')
			{
				dfs(i, j);
			}
		}
	}


	if (cycle)
	{
		cout << "Poor Inna!" << endl;
		return;

	}

	ll ma = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = -1;
		}

	}




	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'D')
			{
				ma = max((foo(i, j) / 4), ma);
				//cout << foo(i, j) << endl;

			}
		}
	}




	if (ma == 0)
	{
		cout << "Poor Dima!" << endl;
		return;
	}


	cout << ma << endl;

}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}