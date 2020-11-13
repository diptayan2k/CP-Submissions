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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;




void solve(int t)
{
	ll p, q;
	cin >> p >> q;

	if (p % q != 0)
	{
		cout << p << endl;
		return;
	}

	vector<ll> v;
	ll x = q;
	while (x % 2 == 0)
	{
		x /= 2;
		v.pb(2);
	}

	for (ll i = 3; i * i <= x; i += 2)
	{
		while (x % i == 0)
		{
			x /= i;
			v.pb(i);
		}
	}

	if (x > 2) v.pb(x);


	sort(v.begin(), v.end());


	ll an = -1;
	for (auto i : v)
	{
		ll d = i;


		while (d <= p)
		{
			//cout << d << endl;
			if (p % d == 0 and (p / d) % q != 0)
			{
				an = max(an, p / d);
			}
			d *= i;

		}

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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}