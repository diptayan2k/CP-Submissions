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


void solve(int t)
{
	ll n, l, r, ql, qr;
	cin >> n >> l >> r >> ql >> qr;
	ll a[n];
	ll b[n + 2];
	b[0] = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i + 1] = a[i] + b[i];
	}
	b[n + 1] = b[n];

	ll ans = INF;

	for (int i = 0; i <= n; i++ )
	{
		ll p = i;
		ll q = n - i;

		ll c = b[i];
		ll d = b[n + 1] - b[i];

		if (p > q)
		{
			ans = min(ans, l * c + r * d + (p - q - 1) * ql);
		}

		if (p < q)
		{
			ans = min(ans, l * c + r * d + (q - p - 1) * qr);
		}

		if (p == q)
		{
			ans = min(ans, l * c + r * d);
		}
	}
	cout << ans << endl;

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