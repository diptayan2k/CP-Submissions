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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
ll mod = 1e9 + 7;
ll INF = 1000000000000000000;

void solve(int t)
{
	ll n;
	cin >> n;
	multiset<pair<ll, ll> > s;
	s.insert({ -1 * n, 1});
	ll a[n + 1] = {0};

	for (int i = 1; i <= n; i++)
	{
		pair<ll, ll> p = (*s.begin());
		s.erase(s.begin());
		ll len = -1 * p.F;
		ll l = p.S;
		ll r = p.S + len - 1;
		ll mid;
		if (len % 2 == 1)
		{
			mid = (l + r) / 2;
		}
		else
		{
			mid = (l + r - 1) / 2;
		}
		s.insert({ -1 * (mid - l), l});
		s.insert({ -1 * (r - mid), mid + 1});
		a[mid] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
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