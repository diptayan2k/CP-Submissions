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
const ll mod = 1000000007;
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

	return (y % 2 == 0) ? p % mod : (x % mod * p % mod) % mod;
}

void solve(int t)
{

	string s;
	cin >> s;

	ll n = s.length();

	ll a[n];
	a[0] = 0;

	ll ten = 1;
	for (int i = 1; i < n; i++)
	{
		a[i] = ((ten % mod * i) % mod + a[i - 1]) % mod;
		a[i] %= mod;
		ten = (ten % mod * 10) % mod;
	}

	ll ans = 0;
	reverse(a, a + n);



	for (ll i = 0; i < n; i++)
	{
		ll p = s[i] - '0';
		ll q = (((i * (i + 1)) / 2) % mod * power(10, n - i - 1) % mod) % mod;
		ans = (ans % mod + ((q % mod + a[i] % mod) % mod * p) % mod) % mod;
		ans %= mod;
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