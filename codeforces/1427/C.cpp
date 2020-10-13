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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;




void solve(int t)
{

	ll r, n;
	cin >> r >> n;

	ll x[n + 1], y[n + 1], tm[n + 1];
	tm[0] = 0;
	x[0] = 1;
	y[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> tm[i] >> x[i] >> y[i];
	}

	ll dp[n + 1];
	dp[0] = 0;

	priority_queue<ll> pq;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = NEGINF ;

		for (int j = max(i - 2 * r , 0ll); j < i; j++)
		{
			if (tm[i] - tm[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (i >= 2 * r)
		{
			pq.push(dp[i - 2 * r]);
			dp[i] = max(dp[i], 1 + pq.top());
		}

	}

	ll ans = 0;

	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, dp[i]);
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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}