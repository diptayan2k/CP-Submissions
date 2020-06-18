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

void solve(int t)
{
	ll k;
	cin >> k;

	ll a[10];
	for (int i = 0; i < 10; i++) a[i] = 1;
	string s = "codeforces";
	ll q = 100;
	while (true)
	{

		for (int i = 0; i < 10; i++)
		{

			ll p = 1;
			for (int j = 0; j < 10; j++)
			{
				p *= a[j];
			}

			//cout << p << endl;

			if (p >= k)
			{

				for (int j = 0; j < 10; j++)
				{
					for (int k = 0; k < a[j]; k++)
					{
						cout << s[j];
					}

				}
				return;
			}
			a[i]++;

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