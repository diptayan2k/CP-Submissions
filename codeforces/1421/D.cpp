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
const ll INF = 2000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

ll xx, yy;
ll c1, c2, c3, c4, c5, c6;

ll foo(ll x, ll y, ll mask)
{

	if (x == xx and y == yy) return 0;


	ll res = INF;
	ll a = INF, b = INF, c = INF, d = INF, e = INF, ff = INF;
	ll aa = INF, aaa = INF, dd = INF, ddd = INF;

	if (xx >= x and yy >= y and (mask & (1ll << 0)) == 0)
	{
		a = c1 * min(xx - x, yy - y) + foo(x + min(xx - x, yy - y), y + min(xx - x, yy - y), mask | (1ll << 0));
		res = min(res, a);
	}
	if (yy >= y and (mask & (1ll << 0)) == 0)
	{
		aa = c1 * (yy - y) + foo(x + (yy - y), y + (yy - y), mask | (1ll << 0));
		res = min(res, aa);
	}
	if (xx >= x and (mask & (1ll << 0)) == 0)
	{
		aaa = c1 * (xx - x) + foo(x + (xx - x), y + (xx - x), mask | (1ll << 0));
		res = min(res, aaa);
	}
	if (yy >= y and (mask & (1ll << 1)) == 0)
	{
		b = c2 * (yy - y) + foo(x, yy, mask | (1ll << 1));
		res = min(res, b);
	}
	if (xx <= x and (mask & (1ll << 2)) == 0)
	{
		c = c3 * (x - xx) + foo(xx, y, mask | (1ll << 2));
		res = min(res, c);

	}
	if (xx <= x and yy <= y and (mask & (1ll << 3)) == 0 )
	{
		d = c4 * min(x - xx, y - yy) + foo(x - min(x - xx, y - yy), y - min(x - xx, y - yy), mask | (1ll << 3));
		res = min(res, d);
	}
	if (xx <= x and (mask & (1ll << 3)) == 0 )
	{
		dd = c4 * (x - xx) + foo(x - (x - xx), y - (x - xx), mask | (1ll << 3));
		res = min(res, dd);
	}
	if (yy <= y and (mask & (1ll << 3)) == 0 )
	{
		ddd = c4 * (y - yy) + foo(x - (y - yy), y - ( y - yy), mask | (1ll << 3));
		res = min(res, ddd);
	}
	if (yy <= y and (mask & (1ll << 4)) == 0)
	{
		e = c5 * (y - yy) + foo(x, yy, mask | (1ll << 4));
		res = min(res, e);
	}
	if (xx >= x and (mask & (1ll << 5)) == 0)
	{
		ff = c6 * (xx - x) + foo(xx, y, mask | (1ll << 5) );
		res = min(res, ff);
	}

	//res = min({res, a, b, c, d, e, ff, aa, dd, aaa, ddd});

	return res;



}

void solve(int t)
{
	cin >> xx >> yy;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	//cout << INF << endl;

	cout << foo(0, 0, 0) << endl;

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