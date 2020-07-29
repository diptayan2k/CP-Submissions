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

ll n, k, z;
ll a[100001];

ll dp[100001][6][2];

ll foo(ll idx, ll num, ll flag)
{
	if (num > z)
	{
		return -INF;
	}
	if (2 * num + idx == k)
	{
		return a[idx];
	}

	if (dp[idx][num][flag] != -1) return dp[idx][num][flag];

	ll res = -INF;

	res = max(a[idx] + foo(idx + 1, num, 0), res);
	if (flag == 0 and idx > 0)
	{
		res = max(a[idx] + foo(idx - 1, num + 1, 1), res);
	}

	return dp[idx][num][flag] = res;

}


void solve(int t)
{

	cin >> n >> k >> z;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= z; j++)
		{
			for (int l = 0; l <= 1; l++)
			{
				dp[i][j][l] = -1;
			}
		}
	}

	cout << foo(0, 0, 0) << endl;





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