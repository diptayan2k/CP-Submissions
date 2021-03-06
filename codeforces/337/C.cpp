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
const ll mod = 1000000009;
const ll INF = 1e18;
const int N = 20;

ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll p = power(x, y / 2) % mod;
	p = (p % mod * p % mod) % mod;

	return (y % 2 == 0) ? p % mod : (x % mod * p % mod) % mod;
}

void solve(int t)
{
	ll n, m, k;
	cin >> n >> m >> k;
	ll d = (n / k) * (k - 1) + (n % k);
	if (m > d)
	{
		ll p = m - d;
		ll q = k * p + k - 1;
		q = q / k;
		ll ans = 0;
		ans = (k * (power(2, (q)) - 1)) % mod;
		ans *= 2;
		ans %= mod;
		ll r = m - q * k;
		ans = (ans + r) % mod;
		cout << ans << endl;
	}
	else
	{
		cout << m % mod << endl;
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