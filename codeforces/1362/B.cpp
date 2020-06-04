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


void solve(int t)
{
	ll n;
	cin >> n;
	set<ll> v, v1;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		v.insert(x);
	}

	for (int i = 1; i <= 1023; i++)
	{
		v1.clear();
		for (auto j : v)
		{
			v1.insert(j ^ i);
		}

		if (v1 == v)
		{
			cout << i << endl;
			return;
		}

	}
	cout << -1 << endl;


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