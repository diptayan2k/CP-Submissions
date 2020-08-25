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
const int N = 18;




void solve(int t)
{
	ll p, f;
	cin >> p >> f;
	ll cnts, cntw;
	cin >> cnts >> cntw;
	ll s, w;
	cin >> s >> w;

	ll ans = 0;

	for (ll i = 0; i <= cnts; i++)
	{
		ll a1 = min(i, p / s);
		ll a2 = min(cnts - i, f / s);
		ll b1 = min(cntw, (p - a1 * s) / w);
		ll b2 = min(cntw - b1, (f - a2 * s) / w);

		ans = max(ans, a1 + a2 + b1 + b2);

		b2 = min(cntw, (f - a2 * s) / w);
		b1 = min(cntw - b2, (p - a1 * s) / w);

		ans = max(ans, a1 + a2 + b1 + b2);

	}

	for (ll i = 0; i <= cntw; i++)
	{
		ll b1 = min(i, p / w);
		ll b2 = min(cntw - i, f / w);
		ll a1 = min(cnts, (p - b1 * w) / s);
		ll a2 = min(cnts - a1, (f - b2 * w) / s);

		ans = max(ans, a1 + a2 + b1 + b2);

		a2 = min(cnts, (f - b2 * w) / s);
		a1 = min(cnts - a2, (p - b1 * w) / s);

		ans = max(ans, a1 + a2 + b1 + b2);

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