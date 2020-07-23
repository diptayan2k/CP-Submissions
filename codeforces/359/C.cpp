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

ll power(ll x, ll y)
{
	if (y == 0) return 1;
	ll q = power(x, y / 2) % mod;
	if (y % 2 == 0)
		return (q * q) % mod;
	else
		return ((q * q) % mod * x) % mod;
}

void solve(int t)
{

	ll n, x;
	cin >> n >> x;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	vector<ll> v;

	for (int i = 0; i < n; i++)
	{
		v.pb(sum - a[i]);
	}

	sort(v.begin(), v.end(), greater<ll>());

	while (v.size() > 0)
	{

		ll mi = v[v.size() - 1];
		ll cnt = 0;
		ll i = v.size() - 1;
		while (i >= 0 and v[i] == mi)
		{
			cnt++;
			i--;
		}

		if (cnt % x == 0)
		{
			ll d = cnt / x;
			while (cnt--)
			{
				v.pop_back();
			}
			while (d--)
			{
				v.pb(mi + 1);
			}
		}
		else break;

	}

	ll p = min(v[v.size() - 1], sum);

	cout << power(x, p) % mod << endl;

}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}