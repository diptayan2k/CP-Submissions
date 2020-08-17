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
const ll INF = 1e18;
const int N = 18;





void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	ll a[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/

	ll len = n + m;
	ll ans = 0;

	for (int i = 1; i <= (len - 1) / 2; i++)
	{
		//cout << i << " ";
		ll cnt0 = 0;
		ll cnt1 = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (k + j + 1 == i or k + j + 1 == len - i)
				{
					if (a[j][k] == 0) cnt0++;
					else cnt1++;
				}

			}
		}
		ans += min(cnt0, cnt1);

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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}