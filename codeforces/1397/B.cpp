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
	ll p = power(x, y / 2);
	p = (p * p) ;

	return (y % 2 == 0) ? p : (x * p);
}


void solve(int t)
{

	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);


	ll an = INF;
	for (ll i = 1; i <= 100000 ; i++)
	{

		ll ans = 0;
		ll pd = 1;

		for (int j = 0; j < n; j++)
		{
			ans += abs(pd - a[j]);
			pd *= i;
		}

		lld v = log10(i);
		v = v * (n  - 1) * 1.0;
		if (v >= 18) break;

		an = min(an, ans);

	}

	cout << an << endl;

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