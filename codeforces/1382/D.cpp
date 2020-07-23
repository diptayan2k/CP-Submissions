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
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;
ll a[4001];
ll n;
vector<ll> v;
bool dp[4001][2001];
bool vis[4001][2001];

bool foo(ll idx, ll sum)
{
	if (sum > n) return false;
	if (sum == n) return true;
	if (idx == v.size())
	{
		if (sum == n) return true;
		else return false;
	}

	if (vis[idx][sum]) return dp[idx][sum];

	bool res = false;

	res |= foo(idx + 1, sum + v[idx]);
	res |= foo(idx + 1, sum);

	vis[idx][sum] = true;

	return dp[idx][sum] = res;
}

void solve(int t)
{
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
	}

	ll b[2 * n] = {0};
	ll ma = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (a[i] > ma)
		{
			b[i] = 1;
			ma = a[i];
		}
	}

	ll len = 0;
	for (int i = 2 * n - 1; i >= 0; i--)
	{

		if (b[i] == 1)
		{
			len++;
			v.pb(len);
			len = 0;
		}
		else
		{
			len++;
		}
	}



	/*
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;*/

	for (int i = 0; i <= 2 * n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			vis[i][j] = false;
			dp[i][j] = false;

		}
	}

	if (foo(0, 0))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	v.clear();

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