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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<pair<ll, ll> > v;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= m; j++)
			{
				v.pb({i, j});

			}
		}
		else
		{
			for (int j = m; j >= 1; j--)
			{
				v.pb({i, j});
			}
		}
	}

	ll d = 0;

	for (int i = 1; i <= k; i++)
	{
		if (i == k)
		{
			cout << v.size() - 2 * (k - 1) << " ";
			for (int j = d; j < v.size(); j++) cout << v[j].F << " " << v[j].S << " ";
		}
		else
		{
			cout << 2 << " " << v[d].F << " " << v[d].S << " ";
			d++;
			cout << v[d].F << " " << v[d].S;
			d++;
		}
		cout << endl;
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