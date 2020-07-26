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

vector<ll> v[1001];
bool vis[1001];
ll n;

ll cn = 0;
vector<ll> d;

void dfs(ll u)
{
	vis[u] = true;
	d.pb(u);

	for (auto i : v[u])
	{
		if (vis[i]) continue;
		dfs(i);
	}
}

void solve(int t)
{

	string s;
	cin >> s;
	n = s.length();
	memset(vis, false, sizeof(vis));

	char ch[n + 1];
	map<char, ll> mp;
	for (int i = 0; i < n; i++)
	{
		mp[s[i]]++;
	}

	for (int i = 4 ; i <= n; i += 2)
	{
		v[2].pb(i);
		v[i].pb(2);
		vis[i] = true;
	}

	for (int i = 3; i <= n; i += 2)
	{
		if (!vis[i])
		{
			for (int j = 2 * i; j <= n; j += i)
			{
				v[i].pb(j);
				v[j].pb(i);
				vis[j] = true;
			}

		}
		vis[i] = true;
	}

	memset(vis, false, sizeof(vis));

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			d.clear();
			dfs(i);

			vector<pair<ll, char> > lol;
			for (char c = 'a'; c <= 'z'; c++)
			{
				lol.pb({mp[c], c});
			}
			sort(lol.begin(), lol.end());
			ll ma = -1;
			char p;

			for (auto j : lol)
			{
				if (j.F >= d.size())
				{
					ma = j.F;
					p = j.S;
					break;
				}
			}

			if (ma < d.size())
			{
				cout << "NO" << endl;
				return;
			}
			for (auto j : d)
			{
				ch[j] = p;
				mp[p]--;
			}
		}
	}

	cout << "YES" << endl;

	for (int i = 1; i <= n; i++) cout << ch[i];
	cout << endl;

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