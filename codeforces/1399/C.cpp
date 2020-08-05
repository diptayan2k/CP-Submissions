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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;



void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0 ; i < n; i++)
	{
		cin >> a[i];
	}


	ll ans = 0;
	ll fr[n + 1] = {0};

	for (int i = 0; i < n; i++) fr[a[i]]++;

	for (int w = 2; w <= 2 * n; w++)
	{
		ll cnt = 0;

		for (int i = 1 ; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				if (i != j and i + j == w)
				{
					cnt += min(fr[i], fr[j]);
				}
				if (i == j and i + j == w)
				{
					cnt += fr[i] / 2;
				}
			}
		}
		ans = max(ans, cnt);

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