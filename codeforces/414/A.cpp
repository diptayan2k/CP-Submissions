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
const int N = 20;

void solve(int t)
{
	ll  n, k;
	cin >> n >> k;
	if (n == 1 )
	{
		if (k == 0) cout << 1 << endl;
		else cout << -1 << endl;
		return;
	}
	ll m = n / 2;
	ll d = k / m;
	ll a[n];
	ll q = k - d * m;

	if (k < m)
	{
		cout << -1 << endl;
		return;
	}

	memset(a, 0, sizeof(a));

	/*
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;*/

	for (int i = 0; i < n; i += 2)
	{
		if (i + 1 < n) {
			a[i] = d;
			a[i + 1] = d;
		}

	}
	//cout << m << endl;
	ll s = 3;
	a[0] += q;
	a[1] += q;
	a[1] *= 2;
	if (n > 3)
	{
		s = a[1] / a[2] + 1;
	}

	for (int i = 2; i < n - (n % 2); i++)
	{
		a[i] *= (s++);
	}

	if (n % 2 == 1) a[n - 1] = a[n - 2] + 1;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
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