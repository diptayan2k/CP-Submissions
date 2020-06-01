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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;
ll n, m, k;

ll check(ll val)
{
	ll res = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll d = val / i;
		res += min(d, m);
	}

	return res;
}


void solve(int t)
{
	cin >> n >> m >> k;

	ll lo = 1;
	ll hi = n * m;
	ll mid;
	ll ans;

	while (lo <= hi)
	{
		mid = (hi + lo) / 2;
		ll d = check(mid);
		if (d >= k)
		{
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	//cout << check(1) << endl;

	//cout << ans << endl;

	ll an = INF;
	for (ll i = 1; i <= n; i++)
	{
		ll lo = 1;
		ll hi = m;
		ll mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (mid * i >= ans)
			{
				hi = mid - 1;
				an = min(an, mid * i);
			}
			else
			{
				lo = mid + 1;
			}
		}
	}

	if (an != INF) ans = max(ans, an);

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