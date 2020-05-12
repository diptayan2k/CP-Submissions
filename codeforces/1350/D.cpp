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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
ll mod = 1e9 + 7;
ll INF = 1000000000000000000;


void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	bool ok = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == k) ok = true;
	}

	if (n == 1)
	{
		if (a[0] == k)
		{
			cout << "yes" << endl;
			return;
		}
		cout << "no" << endl;
		return;

	}

	for (int i = 0; i < n - 1 and n >= 2; i++)
	{
		ll x = a[i];
		ll y = a[i + 1];
		if (x > y) swap(x, y);
		if (x >= k and ok  )
		{
			cout << "yes" << endl;
			return;
		}
	}
	for (int i = 0; i < n - 2 and n >= 3; i++)
	{
		ll b[4];
		for (int j = 0; j < 3; j++)
		{
			b[j + 1] = a[i + j];
		}
		sort(b + 1, b + 4);
		if (b[2] >= k and ok)
		{
			cout << "yes" << endl;
			return;
		}
	}
	cout << "no" << endl;
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