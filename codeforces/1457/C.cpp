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
	ll n, p, k;
	cin >> n >> p >> k;
	string s;
	cin >> s;
	ll x, y;
	cin >> x >> y;
	ll dp[n];

	memset(dp, -1, sizeof(dp));

	for (int i = n - 1, cnt = 0; cnt < k; i--, cnt++)
	{
		if (s[i] == '0') dp[i] = 1;
		else dp[i] = 0;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (i + k < n)
		{
			if (s[i] == '0') dp[i] = 1 + dp[i + k];
			else dp[i] = dp[i + k];
		}
	}

	ll ans = INF;


	/*
	for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	*/
	
	for (int i = p - 1; i < n; i++)
	{
		ans = min(ans, (i - (p - 1)) * y + dp[i] * x);
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