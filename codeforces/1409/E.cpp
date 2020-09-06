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
#define MAX 5

ll n, k;
ll x[200001], y[200001];
ll nxt[200001];

ll dp[200001][3];

ll foo(ll idx, ll cnt)
{
	if (cnt > 2) return NEGINF;
	if (idx == n) return 0;

	if (dp[idx][cnt] != -1) return dp[idx][cnt];

	ll res = NEGINF;

	res = max(res, nxt[idx] - idx + foo(nxt[idx], cnt + 1));
	res = max(res, foo(idx + 1, cnt));

	return dp[idx][cnt] = res;
}


void solve(int t)
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];

	sort(x, x + n);
	ll p = n - 1;

	for (int i = n - 1; i >= 0; i--)
	{
		while (x[p] - x[i] > k) p--;
		nxt[i] = p + 1;
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
	}


	cout << foo(0, 0) << endl;

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