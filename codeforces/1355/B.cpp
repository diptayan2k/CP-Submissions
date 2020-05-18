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

bool ispossible(ll a[], ll val, ll n)
{
	ll cn = 0;
	ll sz = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= ++sz)
		{
			cn++;
			sz = 0;
		}
	}

	if (cn >= val) return true;
	return false;
}



void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	ll lo = 1;
	ll hi = n;
	ll mid;
	ll ans = 0;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (ispossible(a, mid, n))
		{
			lo = mid + 1;
			ans = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}
	cout << ans << endl;

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