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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;
ll tr[500001];
ll a[(1 << 17) + 1];
ll n, m;

void solve(int t)
{
	cin >> n >> m;
	ll sz = (1 << n);
	for (int i = 0; i < (1 << n); i++)
	{
		cin >> a[i];
		tr[i + sz] = a[i];
	}

	for (int i = sz - 1; i > 0; i--)
	{
		ll d = log2(i);
		if ((n - d) % 2 == 0) tr[i] = tr[2 * i] ^ tr[2 * i + 1];
		else tr[i] = tr[2 * i] | tr[2 * i + 1];
	}

	//cout << tr[1] << endl;

	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		x--;
		tr[sz + x] = y;
		ll i = (sz + x) / 2;

		while (i > 0)
		{
			ll d = log2(i);
			if ((n - d) % 2 == 0) tr[i] = tr[2 * i] ^ tr[2 * i + 1];
			else tr[i] = tr[2 * i] | tr[2 * i + 1];
			i /= 2;
		}
		cout << tr[1] << endl;
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