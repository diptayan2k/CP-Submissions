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
ll a, b, n;

bool check(ll cn)
{
	ll d = cn * a + (n - cn) * b;
	while (d != 0)
	{
		if ((d % 10) != a and (d % 10) != b) return false;
		d /= 10;
	}
	return true;
}

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
	cin >> a >> b >> n;
	ll fact[n + 1];
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;

	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (check(i))
		{
			ans = (ans + (fact[n] * power((fact[i] * fact[n - i]) % mod, mod - 2)) % mod) % mod;
		}
	}

	cout << ans % mod << endl;



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