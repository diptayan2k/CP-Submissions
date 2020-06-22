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
	ll n, k;
	cin >> n >> k;
	ll a[n + 1] = {0};
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll pr[n + 1] = {0};

	for (int i = 1; i <= n; i++)
	{
		pr[i] = pr[i - 1] + a[i];
	}

	ll ma = -1;
	ll val = -1;
	for (int i = 1; i <= n; i++)
	{
		ll x = a[i];

		ll lo = 1;
		ll hi = i;
		ll ans = -1;

		while (lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if ((i - mid + 1)*x - (pr[i] - pr[mid - 1]) <= k)
			{
				hi = mid - 1;
				ans = i - mid + 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
		if (ans > ma)
		{
			ma = ans;
			val = a[i];
		}
		if (ans == ma)
		{
			val = min(val, a[i]);
		}
	}

	cout << ma << " " << val << endl;
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