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

ll getmax(ll n)
{
	if (n == 0) return 0;
	ll ma = 0;
	while (n != 0)
	{
		ma = max(ma, n % 10);
		n /= 10;
	}
	return ma;
}

ll getmin(ll n)
{
	if (n == 0) return 0;
	ll mi = 9;
	while (n != 0)
	{
		mi = min(mi, n % 10);
		n /= 10;
	}
	return mi;
}



void solve(int t)
{
	ll n, k;
	cin >> n >> k;

	while (k--)
	{
		ll a = getmin(n);
		ll b = getmax(n);
		if (k > 0) n += a * b;
		if (a == 0) break;

	}

	cout << n << endl;


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