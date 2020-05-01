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
using namespace std;
ll mod = 1000000007;
ll INF = 1000000000000000000;


void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	map<ll, ll> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	if (m.size() > k)
	{
		cout << -1 << endl;
		return;
	}

	ll c[n + 1] = {0};
	for (auto i : m)
	{
		c[i.F] = 1;
	}
	ll p = k - m.size();
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0 and p > 0)
		{
			c[i] = 1;
			p--;
		}
	}


	vector<ll> v;
	cout << n*k << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (c[j] == 1)
			{
				cout << j << " ";
			}
		}
	}
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
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
}
