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
	ll n;
	cin >> n;
	ll a[n + 1];
	ll x = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		x = __gcd(x, a[i]);
	}
	ll suf[n];
	ll pre[n];
	ll g = 0;
	for (int i = 0; i < n; i++)
	{
		pre[i] = g;
		g = __gcd(g, a[i]);
	}
	g = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		suf[i] = g;
		g = __gcd(g, a[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll p = a[i] * (__gcd(suf[i], pre[i]));
		ans = __gcd(ans, p);
	}
	//cout << "HELLO";
	cout << ans / x << endl;
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