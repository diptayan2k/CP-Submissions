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
const int N = 21;


void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll a[n + 1] = {0};
	ll pr[n + 1] = {0};
	for (int i = 0; i < n; i++)
	{
		a[i + 1] = s[i] - '0';
		pr[i + 1] = s[i] - '0' + pr[i];
	}




	ll dp[n + 1] = {0};
	for (int i = 1; i <= n; i++)
	{
		if (s[i - 1] == '1')
		{
			if (i > k + 1)
			{
				dp[i] = dp[i - k - 1] + 1;
			}
			else
			{
				dp[i] = 1;
			}

		}

		else
		{
			if (i > k + 1)
			{
				if (pr[i] - pr[i - k - 1] == 0)
				{
					dp[i] = max(dp[i - 1], dp[i - k - 1] + 1);
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
			else
			{
				if (pr[i] == 0)
				{
					dp[i] = 1;
				}
				else
				{
					dp[i] = dp[i - 1];
				}
			}
		}
	}


	/*
	for (int i = 1; i <= n; i++)
	{
		cout << pr[i] << " " << dp[i] << endl;
	}*/

	cout << dp[n] - pr[n] << endl;



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