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
ll a[100001];
ll n;
ll m[100001] = {0};
ll dp[100001] = {0};



void solve(int t)
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	for (int i = 1; i <= 100000; i++)
	{
		if (m[i] > 0)
		{
			dp[i] = max(dp[i - 1], (m[i] * i + ((i > 2) ? dp[i - 2] : 0)));
		}
		else
		{
			dp[i] = dp[i - 1];
		}
		//cout << dp[i] << " ";
	}
	cout << dp[100000];


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