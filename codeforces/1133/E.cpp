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

ll dp[5001][5001];
ll n, k;
ll a[5001];
ll range[5001];

ll foo(ll idx, ll cnt)
{
	if (cnt == k) return 0;
	if (idx == n)	return 0;

	if (dp[idx][cnt] != -1) return dp[idx][cnt];

	ll res = 0;
	res = max(res, (range[idx] - idx) + foo(range[idx], cnt + 1));
	res = max(res, foo(idx + 1, cnt));

	return dp[idx][cnt] = res;
}

void solve(int t)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));

	sort(a, a + n);
	memset(range, -1, sizeof(range));

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] - a[i] > 5)
			{
				range[i] = j;
				break;
			}

		}
		if (range[i] == -1) range[i] = n;
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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}