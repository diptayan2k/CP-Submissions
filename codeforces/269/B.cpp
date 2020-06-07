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
ll n, m;
vector<pair<lld, ll> > p;
ll dp[5001][5001];

ll foo(ll idx, ll seg_no)
{
	if (seg_no >= m) return -INF;

	if (idx == n)
	{
		if (seg_no <= m - 1) return 0;
		return -INF;
	}

	if (dp[idx][seg_no] != -1) return dp[idx][seg_no];

	ll res;


	if (p[idx].S == seg_no)
	{
		res = 1 + max(max(foo(idx + 1, seg_no + 1), foo(idx + 1, seg_no)), foo(idx, seg_no + 1));
	}
	else
	{
		res = max(max(foo(idx + 1, seg_no + 1), foo(idx + 1, seg_no)), foo(idx, seg_no + 1));
	}


	return dp[idx][seg_no] = res;
}

void solve(int t)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		ll x;
		lld y;
		cin >> x >> y;
		p.pb({y, x - 1});
	}
	sort(p.begin(), p.end());
	/*
	for (auto i : p)
	{
		cout << i.F << " " << i.S << endl;
	}*/
	memset(dp, -1, sizeof(dp));
	cout << n - foo(0, 0) << endl;
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