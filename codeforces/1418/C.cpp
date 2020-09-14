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
ll n;
ll a[200001];
ll dp[200001][3][3];

ll foo(ll idx, ll turn, ll cnt)
{
	if (idx == n) return 0;

	if (dp[idx][turn][cnt] != -1) return dp[idx][turn][cnt];
	ll res = INF;

	if (a[idx] == 1 and turn == 0)
	{
		res = min(res, 1 + foo(idx + 1, turn ^ 1, 0));
		if (cnt == 0) res = min(res, 1 + foo(idx + 1, turn, 1));
	}
	else
	{
		if (cnt == 0) res = min(res, foo(idx + 1, turn, 1));
		res = min(res, foo(idx + 1, turn ^ 1, 0));
	}

	return dp[idx][turn][cnt] = res;
}

void solve(int t)
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
				dp[i][j][k] = -1;
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