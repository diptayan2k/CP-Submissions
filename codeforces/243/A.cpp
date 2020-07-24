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

	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];
	set<ll> s[n];

	for (int i = n - 1; i >= 0; i--)
	{
		s[i].insert(a[i]);
		if (i < n - 1)
		{
			for (auto j : s[i + 1])
			{
				s[i].insert(a[i] | j);
			}
		}
	}
	map<ll, ll> m;

	for (int i = 0; i < n; i++)
	{
		for (auto j : s[i])
		{
			m[j]++;
		}
	}

	cout << m.size() << endl;

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