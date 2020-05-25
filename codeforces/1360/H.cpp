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

ll bs(ll a[], ll n, ll val)
{
	ll lo = 0;
	ll hi = n - 1;
	ll ans = -1;
	ll mid;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (a[mid] >= val)
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		string s;
		ll mask = 0;
		cin >> s;
		for (int j = m - 1; j >= 0; j--)
		{
			ll d = (m - 1 - j);
			if (s[j] == '1') mask |= (1ll << d);
		}
		a[i] = mask;
	}


	sort(a, a + n);

	ll sz = (1ll << m) - n;
	ll pos = (sz - 1) / 2;

	ll hi = ((1ll << m) - 1);
	ll lo = 0;
	ll mid;
	ll ans;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		ll cn = 0;
		cn = bs(a, n, mid) + 1;

		if (mid - cn >= pos)
		{
			hi = mid - 1;
			ans = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}

	while (binary_search(a, a + n, ans))
	{
		ans++;
	}

	string sd;
	for (int i = 0; i < m; i++)
	{
		if (((1ll << i)&ans) != 0) sd += "1";
		else sd += "0";
	}
	reverse(sd.begin(), sd.end());
	cout << sd << endl;
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