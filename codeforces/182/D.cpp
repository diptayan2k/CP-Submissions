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

bool check(string s, string t)
{
	ll n = s.length();
	ll m = t.length();

	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i % m]) return false;
	}
	return true;
}

void solve(int t)
{
	string p, q;
	cin >> p >> q;
	ll n = p.length();
	ll m = q.length();

	ll d = __gcd(n, m);

	vector<ll> v;

	for (int i = 1; i * i <= d; i++)
	{
		if (d % i == 0)
		{
			v.pb(i);
			if (i != d / i)
			{
				v.pb(d / i);
			}
		}

	}

	sort(v.begin(), v.end());
	ll ans = 0;
	for (auto i : v)
	{
		string pp = p.substr(0, i);
		string qq = q.substr(0, i);

		if (pp == qq and check(p, pp) and check(q, qq))
		{
			ans++;
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