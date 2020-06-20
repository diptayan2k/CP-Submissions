#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define mp make_pair
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

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[2 * n];

	vector<ll> v[2];
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
		v[(a[i]) % 2].pb(i + 1);
	}

	vector<pair<ll, ll> > ans;
	for (int i = 0; i < v[0].size(); i += 2)
	{
		if (i + 1 < v[0].size() and ans.size() < n - 1)
		{
			ans.pb({v[0][i], v[0][i + 1]});
		}
	}
	for (int i = 0; i < v[1].size(); i += 2)
	{
		if (i + 1 < v[1].size() and ans.size() < n - 1)
		{
			ans.pb({v[1][i], v[1][i + 1]});
		}
	}

	//op(t) << endl;

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
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}