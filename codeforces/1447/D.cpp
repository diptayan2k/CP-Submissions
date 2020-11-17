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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

ll n, m;
string p, q;
ll dp[5001][5001];

ll foo(ll idx1, ll idx2)
{
	if (idx1 == n or idx2 == m) return 0;


	if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
	ll res = 0;
	if (p[idx1] == q[idx2])
		res = max(res, 2 + foo(idx1 + 1, idx2 + 1));

	res = max(res, -1 + foo(idx1 + 1, idx2));
	res = max(res, -1 + foo(idx1, idx2 + 1));

	return dp[idx1][idx2] = res;
}

void solve(int t)
{
	cin >> n >> m;
	cin >> p >> q;

	memset(dp, -1, sizeof(dp));


	ll ans = NEGINF;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, foo(i, j));
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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}