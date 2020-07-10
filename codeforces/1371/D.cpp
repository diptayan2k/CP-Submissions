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
	ll n, k;
	cin >> n >> k;

	ll a[n][n];
	ll p = k / n;
	ll q = k % n;
	ll b[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = p;
	}
	for (int i = 0; i < q; i++) b[i]++;

	memset(a, 0, sizeof(a));
	ll l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b[i]; j++)
		{
			a[i][l % n] = 1;
			l++;
		}

	}

	ll j = 0;



	if (k % n == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << 2 << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
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
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}