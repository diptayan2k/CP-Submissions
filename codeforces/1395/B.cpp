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
	ll n, m, x, y;
	cin >> n >> m >> x >> y;
	ll sx = x, sy = y;
	cout << x << " " << y << endl;
	y = 1;
	ll itr = 0;
	for (int i = x; i < n + x; i++)
	{

		//cout << i << endl;
		for (int j = 1; j <= m and itr % 2 == 0; j++)
		{
			if (i != sx or j != sy)
			{
				if (i > n)
				{
					cout << i - n << " " << j << endl;
				}
				else
					cout << i << " " << j << endl;
			}
		}
		for (int j = m; j >= 1 and itr % 2 == 1; j--)
		{
			if (i != sx or j != sy)
			{
				if (i > n)
				{
					cout << i - n << " " << j << endl;
				}
				else
					cout << i << " " << j << endl;
			}
		}

		itr++;

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