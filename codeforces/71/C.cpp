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
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll x = n;

	set<ll> s;

	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			s.insert(i);
			s.insert(n / i);
		}
	}


	for (auto i : s)
	{
		//cout << i << endl;

		if (n / i > 2)
		{
			map<ll, ll> m;

			for (int j = 0; j < n; j++)
			{
				if (a[j] == 1)
					m[j % i]++;
			}

			for (auto j : m)
			{
				//cout << j.F << " " << j.S << " " << i << endl;
				if (j.S == n / i)
				{
					//cout << i << endl;
					cout << "YES" << endl;
					return;
				}
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