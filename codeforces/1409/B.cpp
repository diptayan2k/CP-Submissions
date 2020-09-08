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
#define MAX 5


void solve(int t)
{

	ll a, b, n, x, y;
	cin >> a >> b >> x >> y >> n;

	ll p = a;
	ll q = b;
	ll ans = INF;
	ll d = n;
	if (a - x >= d)
	{
		a -= d;
		d = 0;
	}
	else
	{
		d -= (a - x);
		a = x;
	}
	if (d > 0)
	{
		b -= d;
		b = max(b, y);
	}
	ans = min(ans, a * b);

	a = p;
	b = q;
	d = n;

	if (b - y >= d)
	{
		b -= d;
		d = 0;
	}
	else
	{
		d -= (b - y);
		b = y;
	}
	if (d > 0)
	{
		a -= d;
		a = max(a, x);
	}

	ans = min(ans, a * b);

	a = p;
	b = q;

	if (n % 2 == 0)
	{
		ll pp = max(a - n / 2, x) * max(b - n / 2, y);
		ans = min(ans, pp);
	}
	if (n % 2 == 1)
	{
		ll pp = max(a - n / 2, x) * max(b - n / 2 - 1, y);
		ans = min(ans, pp);
		pp = max(a - n / 2 - 1, x) * max(b - n / 2, y);
		ans = min(ans, pp);
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