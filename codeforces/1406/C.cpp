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

ll n;
vector<ll> v[300001];
ll subtr[300001];
ll mis[300001];
ll mi = INF;

void dfs(ll u, ll par)
{
	subtr[u] = 1;
	mis[u] = NEGINF;
	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs(i, u);
		subtr[u] += subtr[i];
		mis[u] = max(mis[u], subtr[i]);
	}

	mis[u] = max(mis[u], n - subtr[u]);
	mi = min(mi, mis[u]);
}

void solve(int t)
{
	mi = INF;

	cin >> n;

	for (int i = 0; i <= n; i++) v[i].clear();

	for (int i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);


	vector<ll> centeroid;
	//cout << mi << endl;
	for (int i = 1; i <= n; i++)
	{
		//cout << mis[i] << " ";
		if (mis[i] == mi)
		{
			centeroid.pb(i);
		}
	}

	//cout << endl;

	//for (auto i : centeroid) cout << i << " ";
	//cout << endl;

	if (centeroid.size() == 2)
	{
		ll p = centeroid[0];
		ll q = centeroid[1];

		for (auto i : v[p])
		{
			if (i != q)
			{
				cout << p << " " << i << endl;
				cout << q << " " << i << endl;
				return;
			}

		}
	}

	ll p = centeroid[0];

	cout << p << " " << v[p][0] << endl;
	cout << p << " " << v[p][0] << endl;



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