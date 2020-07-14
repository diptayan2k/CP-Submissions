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
set<ll> s;

void foo(ll idx, ll num)
{
	if (num != 0)
		s.insert(num);

	if (idx == 10)
	{
		return;
	}


	foo(idx + 1, num * 10 + 4);
	foo(idx + 1, num * 10 + 7);


}

void solve(int t)
{
	foo(0, 0);
	//cout << s.size() << endl;
	vector<ll> v;
	for (auto i : s)
		v.pb(i);

	ll l, r;
	cin >> l >> r;
	ll p = -1;
	ll q = -1;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= l) {p = i; break; }
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < r) {q = i;  }
	}

	ll pr = v[p] + 1;
	ll ans = 0;
	//cout << p << " " << q << endl;
	for (int i = p + 1; i <= q; i++)
	{
		//cout << v[i] << " " << pr << endl;

		ans += (v[i] - pr + 1) * v[i];
		pr = v[i] + 1;
	}
	//cout << ans << endl;
	if (q < p) ans = (r - l + 1) * v[p];
	else
	{
		ans += (v[p] - l + 1) * v[p];
		ans += (r - v[q]) * v[q + 1];
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

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}