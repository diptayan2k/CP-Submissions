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
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define policy tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;


ll n;
ll a [200001], b[200001];
vector<ll> v[200001], g[200001];
map<ll, ll> mp;
ll ext[200001] = {0};
ll lol[200001] = {0};
ll an[200001];

stack<ll> st;
bool vis[200001];



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

void dfs1(ll u)
{
	vis[u] = true;
	//cout << u << " ";
	for (auto i : g[u])
	{
		if (vis[i]) continue;
		dfs1(i);
	}
	st.push(u);
}

void solve(int t)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1 ; i <= n; i++)
	{
		cin >> b[i];
		if (b[i] != -1)
		{
			v[i].pb(b[i]);
			mp[b[i]]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (mp[i] == 0)
		{
			dfs(i);
		}
	}

	vector<ll> odr;

	while (!st.empty())
	{
		odr.pb(st.top());
		st.pop();
	}


	ll ans = 0;

	mp.clear();

	for (auto i : odr)
	{
		//cout << i << endl;

		ll d = ext[i] + a[i];
		ans += d;
		//cout << i << " " << d << endl;
		if (d > 0 and b[i] != -1)
		{
			g[i].pb(b[i]);
			mp[b[i]]++;
		}
		if (d < 0 and b[i] != -1)
		{
			g[b[i]].pb(i);
			mp[i]++;
		}
		an[i] = d;
		if (b[i] != -1)
			ext[b[i]] += max(d, (ll)0);
	}

	cout << ans << endl;

	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		if (mp[i] == 0)
		{
			//cout << i << endl;
			dfs1(i);
			//cout << endl;
		}
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
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