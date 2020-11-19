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
const ll mod1 = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;





void solve(int t)
{

	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	ll s = 0;

	for (int i = 0; i < n; i++) s += a[i];

	sort(a, a + n);

	ll ans = NEGINF;

	ll m = n - 1;
	for (int i = 0; i < n; i++)
	{
		ll req;
		if (i < n - 1)
		{
			req = a[n - 1] * m;
		}
		else req = a[n - 2] * m;



		ll sm = s - a[i];
		ll rem = req - sm;

		if (a[i] <= rem)
		{
			ans = max(ans, rem - a[i]);
		}
		else
		{
			ll d = (a[i] - rem) / m;
			if ((a[i] - rem) % m != 0) d++;
			ans = max(ans, rem + d * m - a[i]);
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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}