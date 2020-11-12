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
	vector<ll> v[n + 1];

	for (int i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	ll ma = 0;
	ll node = -1;

	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() > ma)
		{
			ma = v[i].size();
			node = i;
		}
	}

	vector<bool> vis(n + 1, false);
	vector<pair<ll, ll> > ans;
	queue<ll> q;
	q.push(node);
	vis[node] = true;

	while (!q.empty())
	{
		ll u = q.front();
		q.pop();

		for (auto i : v[u])
		{
			if (vis[i]) continue;
			vis[i] = true;
			ans.pb({u, i});
			q.push(i);
		}
	}

	for (auto i : ans)
	{
		cout << i.F << " " << i.S << endl;
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