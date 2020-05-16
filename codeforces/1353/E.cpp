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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
ll mod = 1e9 + 7;
ll INF = 1000000000000000000;

void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	string s;
	cin >> s;
	a[0] = 0;
	for (int i = 0; i < n; i++)
	{
		a[i + 1] = s[i] - '0';
	}
	ll pr[n + 1];
	pr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		pr[i] = pr[i - 1] + a[i];
	}
	ll ans[n + 1] = {0};
	for (int i = 1; i <= n; i++)
	{
		if (i < k)
		{
			ans[i] = pr[i - 1];
			if (a[i] == 0) ans[i]++;
		}
		else
		{
			ans[i] = pr[i - 1];
			ans[i] = min(ans[i], pr[i - 1] - pr[i - k] + ans[i - k]);
			if (a[i] == 0) ans[i]++;
		}
	}

	/*
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}*/

	//cout << endl;

	ll d = INF;
	for (int i = 1; i <= n; i++)
	{
		d = min(d, ans[i] + pr[n] - pr[i]);
	}
	cout << min(d, pr[n]) << endl;



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