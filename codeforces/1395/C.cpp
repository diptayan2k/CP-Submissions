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

ll mat[201][201];
ll n, m;


void solve(int t)
{

	cin >> n >> m;
	ll a[n];
	ll b[m];

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = (a[i] & b[j]);
		}
	}

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/

	for (ll i = 0; i < (1ll << 9); i++)
	{
		//cout << i << endl;
		ll cnt = 0;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if ((mat[j][k] | i) == i)
				{
					cnt++;
					break;
				}

			}
		}

		if (cnt == n)
		{
			cout << i << endl;
			return;
		}

	}





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