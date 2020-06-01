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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;
ll n, k;
ll dp[2001][2001];

ll foo(ll cn, ll curr)
{
	if (curr > n) return 0;
	if (cn == k)
	{
		return 1;
	}

	if (dp[cn][curr] != -1) return dp[cn][curr];

	ll res = 0;
	for (int i = curr; i <= n; i += curr)
	{
		res = (res + foo(cn + 1, i)) % mod;
	}
	return dp[cn][curr] = res % mod;
}

void solve(int t)
{
	cin >> n >> k;
	ll ans = 0;
	memset(dp, - 1, sizeof(dp));
	cout << foo(0, 1) << endl;
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