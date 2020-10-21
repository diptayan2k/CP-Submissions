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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

ll n, m, k;
ll mat[75][75];
ll x;
ll dp[75][75][75][75];

ll foo(ll i, ll j, ll cnt, ll rem)
{

	if (i == n)
	{
		if (rem % k == 0) return 0;
		return NEGINF;
	}

	if (dp[i][j][cnt][rem] != -1) return dp[i][j][cnt][rem];

	ll res = NEGINF;



	if (cnt < x and j < m - 1)
		res = max(res, mat[i][j] + foo(i, j + 1, cnt + 1, (mat[i][j] + rem) % k));
	if (j < m - 1)
		res = max(res, foo(i, j + 1, cnt, rem));

	if (cnt < x)
		res = max(res, mat[i][j] + foo(i + 1, 0, 0, (mat[i][j] + rem) % k));
	res = max(res, foo(i + 1, 0, cnt, rem));

	return dp[i][j][cnt][rem] = res;
}

void solve(int t)
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	x = m / 2;

	memset(dp, -1, sizeof(dp));

	cout << max((ll)0, foo(0, 0, 0, 0)) << endl;



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