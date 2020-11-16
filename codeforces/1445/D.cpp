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
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



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
	ll n;
	cin >> n;
	ll m = 2 * n;

	ll ar[m];

	for (int i = 0; i < m; i++) cin >> ar[i];


	sort(ar, ar + m);

	reverse(ar + n, ar + m);

	ll ans = 0;

	for (int i = 0; i < n; i++)
		ans = (ans % mod + abs(ar[i] - ar[i + n])) % mod;

	ll fact[m + 1];
	fact[0] = 1;

	for (int i = 1; i <= m; i++) fact[i] = (fact[i - 1] % mod * i % mod) % mod;

	ll ncr = (fact[m] % mod * power((fact[n] * fact[n]) % mod, mod - 2) % mod) % mod;



	cout << (ans * ncr) % mod << endl;




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