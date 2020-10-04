#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
#define endl "\n"
using namespace std;
const ll mod = 998244353;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{
	ll n, m;
	vector<vector<ll> > v;
	cin >> n >> m;
	ll a[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	ll ans = 0;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			ll p = a[i][j];
			ll q = a[n - i - 1][j];
			ll r = a[i][m - j - 1];
			ll s = a[n - i - 1][m - 1 - j];

			ll avg = (p + q + r + s) / 4;
			ll an =  abs(p - avg) + abs(q - avg) + abs(r - avg) + abs(s - avg);
			avg++;
			an =  min(an, abs(p - avg) + abs(q - avg) + abs(r - avg) + abs(s - avg));
			avg = p;
			an =  min(an, abs(p - avg) + abs(q - avg) + abs(r - avg) + abs(s - avg));
			avg = q;
			an =  min(an, abs(p - avg) + abs(q - avg) + abs(r - avg) + abs(s - avg));
			avg = r;
			an =  min(an, abs(p - avg) + abs(q - avg) + abs(r - avg) + abs(s - avg));
			avg = s;
			an =  min(an, abs(p - avg) + abs(q - avg) + abs(r - avg) + abs(s - avg));

			ans += an;

		}
	}

	if (n % 2 == 1)
	{
		ll i = n / 2;

		for (int j = 0; j < m / 2; j++)
		{
			ll p = a[i][j];
			ll q = a[i][m - j - 1];
			ll avg = (p + q) / 2;
			ll an = abs(p - avg) + abs(q - avg);
			avg++;
			an = min(an, abs(p - avg) + abs(q - avg));
			avg = p;
			an = min(an, abs(p - avg) + abs(q - avg));
			avg = q;
			an = min(an, abs(p - avg) + abs(q - avg));
			ans += an;

		}
	}

	if (m % 2 == 1)
	{
		ll j = m / 2;

		for (int i = 0; i < n / 2; i++)
		{
			ll p = a[i][j];
			ll q = a[n - i - 1][j];
			ll avg = (p + q) / 2;
			ll an1 = abs(p - avg) + abs(q - avg);
			avg++;
			ll an2 = abs(p - avg) + abs(q - avg);
			ans += min(an1, an2);

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