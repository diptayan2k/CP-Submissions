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


void solve(int t)
{
	string a, b;
	cin >> a >> b;
	vector<ll> v[26];

	for (int i = 0; i < a.length(); i++)
	{
		v[a[i] - 'a'].pb(i);
	}

	ll pos[26] = {0};
	ll ans = 1;
	/*
	for (int i = 0; i <= 25; i++)
	{
		for (auto j : v[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}*/

	ll prev = -1;
	for (int i = 0; i < b.length(); i++)
	{
		ll x = b[i] - 'a';
		if (v[x].empty())
		{
			cout << -1 << endl;
			return;
		}


		while (pos[x] < v[x].size() and v[x][pos[x]] <= prev)
		{
			pos[x]++;

		}

		if (pos[x] == v[x].size())
		{
			for (int j = 0; j <= 25; j++) pos[j] = 0;
			ans++;
		}
		prev = v[x][pos[x]];
		//cout << x << " " << pos[x] << " " << endl;
		//cout << prev << endl;

	}

	cout << ans << endl;




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