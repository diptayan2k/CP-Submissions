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
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	ll previous[n], next[n];

	ll d = 0;
	previous[0] = -1;
	next[n - 1] = n + 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
		{
			previous[i] = d;
			d = i;
		}
		else
		{
			previous[i] = previous[i - 1];
		}


	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << previous[i] << " ";
	}
	cout << endl;*/
	d = n - 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] != a[i + 1])
		{
			next[i] = d;
			d = i;
		}
		else
		{
			next[i] = next[i + 1];
		}
		//cout << next[i] << " " ;
	}

	/*
	for (int i = 0; i < n; i++)
	{
		cout << next[i] << " ";
	}

	cout << endl;*/


	ll b[n] = {0};
	ll c[n] = {0};

	ll p = 0;
	while (a[p] == a[0]) p++;
	ll q = n - 1;
	while (a[q] == a[n - 1]) q--;

	//cout << p << " " << q << endl;

	for (int i = p; i <= q; i++)
	{
		if (a[i] > a[previous[i]] and a[i] > a[next[i]] ) b[i] = 1;
		if (a[i] < a[previous[i]] and a[i] < a[next[i]]) c[i] = 1;
	}

	/*

	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}

	cout << endl;*/


	ll prb[n + 1] = {0};
	ll prc[n + 1] = {0};

	for (int i = 1; i <= n; i++)
	{
		prb[i] = prb[i - 1] + b[i - 1];
		prc[i] = prc[i - 1] + c[i - 1];
	}



	while (m--)
	{
		ll l, r;
		cin >> l >> r;
		if (r - l + 1 <= 2)
		{
			cout << "Yes" << endl;
			continue;
		}

		ll p = next[l - 1] + 1;
		ll q = previous[r - 1] + 1;


		if (q < p)
		{
			cout << "Yes" << endl;
			continue;
		}
		if (prc[q] - prc[p - 1] == 0)
		{

			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
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