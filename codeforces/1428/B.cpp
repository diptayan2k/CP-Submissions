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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

vector<ll> v[300001];
vector<ll> g[300001];
ll n;
stack<ll> st;
bool vis[300001];
ll ss[300001];
ll sz;

void dfs(ll u)
{
	vis[u] = true;

	for (auto i : v[u])
	{
		if (vis[i]) continue;
		dfs(i);
	}

	st.push(u);
}

void dfs1(ll u, ll src)
{
	sz++;
	vis[u] = true;
	ss[u] = src;

	for (auto i : g[u])
	{
		if (vis[i]) continue;
		dfs1(i, src);
	}


}

void solve(int t)
{
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		vis[i] = false;
		if (s[i] == '>') v[i].pb((i + 1) % n);
		else if (s[i] == '<') v[(i + 1) % n].pb(i);
		else
		{
			v[i].pb((i + 1) % n);
			v[(i + 1) % n].pb(i);
		}

		if (s[i] == '<') g[i].pb((i + 1) % n);
		else if (s[i] == '>') g[(i + 1) % n].pb(i);
		else
		{
			g[i].pb((i + 1) % n);
			g[(i + 1) % n].pb(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i]) dfs(i);
	}

	for (int i = 0; i < n; i++)
	{
		vis[i] = false;
		ss[i] = -1;
	}

	map<ll, ll> mp;

	while (!st.empty())
	{
		ll x = st.top();
		//cout << x << endl;

		st.pop();

		if (!vis[x])
		{
			sz = 0;
			//cout << x << " ";
			dfs1(x, x);
		}
		mp[x] = sz;

	}




	ll cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (mp[ss[i]] > 1) cnt++;
		v[i].clear();
		g[i].clear();
	}

	cout << cnt << endl;




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