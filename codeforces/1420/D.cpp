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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll p = power(x, y / 2) % mod;
	p = (p % mod * p % mod) % mod;

	return (y % 2 == 0) ? p : (x * p) % mod;
}

ll fact[300000 + 1];
ll modinv[300001];

ll ncr(ll n, ll k)
{
	if (k > n) return 0;
	return (fact[n] % mod * (modinv[k] % mod * modinv[n - k] % mod) % mod) % mod;
}

void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	pair<ll, ll> p[n], q[n];

	fact[0] = 1;
	for (int i = 1;  i <= n; i++) fact[i] = (fact[i - 1] % mod * i) % mod;

	for (int i = 0; i <= n; i++)
	{
		modinv[i] = power(fact[i], mod - 2) % mod;
	}



	for (int i = 0; i < n; i++)
	{
		cin >> p[i].F >> p[i].S;
	}


	map<ll, ll> mp;
	map<ll, ll> in, out;

	for (int i = 0; i < n; i++)
	{
		mp[p[i].F]++;
		mp[p[i].S + 1]++;
		in[p[i].F]++;
		out[p[i].S + 1]++;
	}


	int cnt = 0;
	ll ans = 0;

	for (auto i : mp)
	{

		cnt -= out[i.F];
		ans = (ans - ncr(cnt, k) + mod) % mod;
		cnt += in[i.F];
		ans = (ans + ncr(cnt, k)) % mod;
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