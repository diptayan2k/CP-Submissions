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

void solve(int t)
{
	ll a, b;
	cin >> a >> b;
	vector<pair<ll, ll> > v1, v2;

	ll p, q, r, s;
	bool flag = 0;
	for (int i = 1; i < a; i++)
	{
		for (int j = 1; j < a; j++)
		{
			if (i * i + j * j == a * a)
			{
				v1.pb({i, j});
			}
		}
	}



	for (int i = 1; i < b; i++)
	{
		for (int j = 1; j < b; j++)
		{
			if (i * i + j * j == b * b)
			{
				v2.pb({i, j});
			}
		}
	}

	for (auto i : v1)
	{
		for (auto j : v2)
		{
			if ((i.F + j.F) * (i.F + j.F) + (i.S - j.S) * (i.S - j.S) == a * a + b * b and (i.F + j.F) != 0 and (i.S - j.S) != 0 )
			{
				cout << "YES" << endl;
				cout << 0 << " " << 0 << endl;
				cout << i.F << " " << i.S << endl;
				cout << -j.F << " " << j.S << endl;
				return;
			}

		}
	}



	cout << "NO" << endl;



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