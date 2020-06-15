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
ll n, k, d;
ll dp[101][101][2];


ll foo(ll lvl, ll sum, ll flag)
{
	if (sum == n and flag == 1)
	{
		return 1;
	}
	if (sum > n)
	{
		return 0;
	}
	if (lvl == n)
	{
		return 0;
	}

	if (dp[lvl][sum][flag] != -1) return dp[lvl][sum][flag];

	ll res = 0;

	for (int i = 1; i <= k; i++)
	{
		if (i >= d)
		{
			res = (res + foo(lvl + 1, sum + i, 1)) % mod;
		}
		else
		{
			res = (res + foo(lvl + 1, sum + i, flag)) % mod;
		}
	}

	return dp[lvl][sum][flag] = res % mod;

}

void solve(int t)
{
	cin >> n >> k >> d;
	memset(dp, -1, sizeof(dp));
	cout << foo(0, 0, 0) % mod << endl;

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