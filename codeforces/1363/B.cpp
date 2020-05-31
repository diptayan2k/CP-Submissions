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
ll n;
string s;
ll a[1001];
ll dp[1001][2][3];

ll foo(ll idx, ll st, ll cn)
{
	if (cn > 1) return INF;

	if (idx == n)
	{
		return 0;
	}

	if (dp[idx][st][cn] != -1) return dp[idx][st][cn];

	ll res = INF;

	if (st == 0)
	{
		res = min(res, (a[idx] == 0) + foo(idx + 1, 1, cn + 1));
		res = min(res, (a[idx] == 1) + foo(idx + 1, 0, cn));
	}
	if (st == 1)
	{
		res = min(res, (a[idx] == 1) + foo(idx + 1, 0, cn + 1));
		res = min(res, (a[idx] == 0) + foo(idx + 1, 1, cn));
	}

	return dp[idx][st][cn] = res;
}


void solve(int t)
{
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
		//cout << a[i] << " ";
	}
	//cout << endl;

	ll ans = INF;
	memset(dp, -1, sizeof(dp));
	ans = min(ans, foo(0, 1, 0));
	memset(dp, -1, sizeof(dp));
	ans = min(ans, foo(0, 0, 0));
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