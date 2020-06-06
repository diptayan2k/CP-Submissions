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
	string s;
	cin >> s;
	ll n = s.length();
	vector<ll> a[2], b[2];

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a')
		{
			a[i % 2].pb(i);
		}
		else
		{
			b[i % 2].pb(i);
		}
	}

	ll odd = 0, even = 0;

	odd = n;

	if (a[0].size() > 0)
	{
		odd += a[0].size() * (a[0].size() - 1) / 2;
	}
	if (a[1].size() > 0)
	{
		odd += a[1].size() * (a[1].size() - 1) / 2;
	}
	if (b[0].size() > 0)
	{
		odd += b[0].size() * (b[0].size() - 1) / 2;
	}
	if (b[1].size() > 0)
	{
		odd += b[1].size() * (b[1].size() - 1) / 2;
	}

	for (auto i : a[0])
	{
		even += a[1].end() - upper_bound(a[1].begin(), a[1].end(), i);
	}
	for (auto i : a[1])
	{
		even += a[0].end() - upper_bound(a[0].begin(), a[0].end(), i);
	}
	for (auto i : b[0])
	{
		even += b[1].end() - upper_bound(b[1].begin(), b[1].end(), i);
	}
	for (auto i : b[1])
	{
		even += b[0].end() - upper_bound(b[0].begin(), b[0].end(), i);
	}

	cout << even << " " << odd << endl;



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