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

ll n;
ll a[2001];
ll dp[2001][3][3];

ll foo(ll idx, ll pr, ll cnt)
{

	if (cnt == 2) return NEGINF;
	if (idx == n) return 0;

	if (dp[idx][pr][cnt] != -1) return dp[idx][pr][cnt];
	ll res = NEGINF;
	if (pr == 1 or pr == 0)
	{
		res = max(res, 1 + foo(idx + 1, a[idx], cnt));
	}
	if (pr == 2)
	{
		if (a[idx] == 2)
		{
			res = max(res, 1 + foo(idx + 1, a[idx], cnt));
		}
		else
		{
			res = max(res, 1 + foo(idx + 1, a[idx], cnt + 1));
		}
	}

	res = max(res, foo(idx + 1, pr, cnt));

	return dp[idx][pr][cnt] = res;

}

void solve(int t)
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}