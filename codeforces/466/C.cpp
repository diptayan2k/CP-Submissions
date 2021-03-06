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
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	ll pr[n + 1];
	pr[0] = 0;

	for (int i = 0; i < n; i++)
	{
		pr[i + 1] = pr[i] + a[i];
	}

	if (pr[n] % 3 != 0)
	{
		cout << 0 << endl;
		return;
	}

	ll sum_part = pr[n] / 3;
	ll p = 0, q = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pr[i] == sum_part) p++;

		if (i > 1 and i < n)
		{
			if (pr[i] == 2 * sum_part)
			{
				ans += (p - (sum_part == 0));
			}
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