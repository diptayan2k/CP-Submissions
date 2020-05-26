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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	ll fr[102] = {0};
	for (int i = 0; i < n; i++) cin >> a[i];
	ll odd = 0, ev = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) ev++;
		else odd++;
		fr[a[i]]++;
	}

	if (((ev % 2) ^ (odd % 2)) == 1)
	{
		cout << "NO" << endl;
		return;
	}
	if (ev % 2 == 0)
	{
		cout << "YES" << endl;
		return;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (fr[i] == 0) continue;
		if (fr[i + 1] != 0 or fr[i - 1] != 0)
		{
			cout << "YES" << endl;
			return;
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
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}