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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;


void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	vector<ll> v;

	for (int i = 1; i < n; i++)
	{
		v.pb(a[i] - a[i - 1]);
	}

	if (v.empty())
	{
		cout << -1 << endl;
	}

	if (v.size() == 1)
	{
		if (v[0] == 0)
		{
			cout << 1 << endl << a[0] << endl;
			return;
		}
		else if (v[0] % 2 == 0)
		{
			cout << 3 << endl;
			cout << a[0] - v[0] << " " << a[0] + v[0] / 2 << " " << a[1] + v[0] << endl;
			return;
		}
		else
		{
			cout << 2 << endl;
			cout << a[0] - v[0] << " " << a[1] + v[0] << endl;
			return;

		}
	}
	else
	{
		sort(v.begin(), v.end());
		map<ll, ll> m;
		for (auto i : v)
		{
			m[i]++;
		}
		if (m.size() > 2)
		{
			cout << 0 << endl;
			return;
		}
		if (m.size() == 2)
		{
			auto itr = m.begin();
			pair<ll, ll> d = (*itr);
			ll p = d.F;
			ll q = d.S;
			itr++;
			d = *itr;
			ll r = d.F;
			ll s = d.S;

			//cout << p << " " << q << " " << r << " " << s << endl;

			if ((q != 1 and s != 1) or (max(p, r) != 2 * (min(p, r))) or (p == 0 or q == 0))
			{
				cout << 0 << endl;
				return;
			}
			if (q != 1 or p < r)
			{
				swap(p, r);
				swap(q, s);
			}

			if (p > r and q != 1)
			{
				cout << 0 << endl;
				return;
			}

			if (p % 2 != 0 or p < r)
			{
				cout << 0 << endl;
				return;
			}

			for (int j = 0; j < n - 1; j++)
			{

				if (a[j] + p == a[j + 1])
				{
					cout << 1 << endl << a[j] + p / 2 << endl;
					return;
				}
			}

		}
		if (m.size() == 1)
		{
			auto itr = m.begin();
			pair<ll, ll> p = *itr;

			if (p.F == 0)
			{
				cout << 1 << endl << a[0] << endl;
				return;
			}
			else
			{
				cout << 2 << endl << a[0] - p.F << " " << a[n - 1] + p.F << endl;
				return;
			}
		}


	}

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