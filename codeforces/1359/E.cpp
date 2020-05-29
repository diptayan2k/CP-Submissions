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
const ll mod = 998244353;
const ll INF = 1e18;
const int N = 21;
ll fact[1000001];

ll power(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b == 1) return a;

	ll p = power(a, b / 2) % mod;

	if (b % 2 == 0)
		return (p * p) % mod;
	else return ((p * p) % mod * a) % mod;
}


void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}

	ll ans = 0;
	k--;
	for (int i = 1; i <= n; i++)
	{
		ll d = n / i - 1;
		if (k <= d)
			ans = (ans + (fact[d] * power((fact[d - k] * fact[k]) % mod, mod - 2)) % mod) % mod;
	}
	//cout << power(1, mod - 2);
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