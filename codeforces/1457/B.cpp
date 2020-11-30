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
const ll mod1 = 1000000007;
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	for (int i = 0; i < n; i++) cin >> a[i];

	a[n + 1] = 0;

	ll ans = INF;
	for (int i = 1; i <= 100; i++)
	{
		ll an = 0;
		ll cnt = 0;
		a[n] = i;

		for (int j = 0; j < n; j++)
		{
			if (a[j] != i or cnt > 0) cnt++;
			if (cnt == k and j < n - 1)
			{
				an++;
				cnt = 0;
			}
			if (j == n - 1 and cnt > 0)
				an++;

		}

		//cout << an << endl;

		ans = min(ans, an);
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