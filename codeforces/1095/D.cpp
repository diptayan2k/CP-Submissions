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
	ll n;
	cin >> n;
	map<pair<ll, ll>, ll> mp;

	vector<ll> ans;
	vector<bool> vis(n + 1, false);

	ll x[n + 1], y[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		mp[ {i, x[i]}] = 1;
		mp[ {i, y[i]}] = 1;
	}

	ans.pb(1);
	vis[1] = true;

	while (ans.size() < n)
	{
		ll u = ans.back();
		ll p = x[u];
		ll q = y[u];

		if (mp[ {p, q}] and !vis[p])
		{
			ans.pb(p);
			vis[p] = true;
		}
		else
		{
			ans.pb(q);
			vis[q] = true;
		}
	}

	for (auto i : ans) cout << i << " ";

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