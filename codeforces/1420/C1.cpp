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




void solve(int t)
{
	ll n, q;
	cin >> n >> q;

	ll a[n + 2];

	a[0] = -1;
	a[n + 1] = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	vector<ll> v;

	for (int i = 1; i <= n; i++)
	{
		ll x = v.size();

		if (x % 2 == 0)
		{
			if (a[i] > a[i - 1] and a[i] > a[i + 1]) v.pb(a[i]);
		}
		else
		{
			if (a[i] < a[i - 1] and a[i] < a[i + 1]) v.pb(a[i]);
		}
	}

	ll ans = 0;

	for (int i = 0; i < v.size(); i += 2) ans += v[i];
	for (int i = 1; i < v.size(); i += 2) ans -= v[i];

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