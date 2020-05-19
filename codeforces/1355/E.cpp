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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
ll a, r, m;
ll arr[100000 + 1], pre[100000 + 1];
ll n;

ll min_cost(ll val)
{
	ll lo = 1;
	ll hi = n;
	ll mid;
	ll idx = 0;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (arr[mid] <= val)
		{
			idx = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	ll less = pre[idx] - idx * val;
	ll more = (pre[n] - pre[idx]) - (n - idx) * val;

	ll cost = 0;
	if (m < a + r)
	{
		ll p = min(-1 * less, more);
		cost += p * m;
		less += p;
		more -= p;
	}


	cost += (-1 * less) * a;
	cost += more * r;

	return cost;

}

void solve(int t)
{
	cin >> n >> a >> r >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + arr[i];
	}

	//cout << min_cost(4) << endl;

	ll lo = 0;
	ll hi = 1e9;
	ll mid;
	ll ans;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;

		if (min_cost(mid) <= min_cost(mid - 1))
		{
			ans = min_cost(mid);
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
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