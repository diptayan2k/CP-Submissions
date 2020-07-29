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
const int N = 20;






void solve(int t)
{
	string s;
	cin >> s;
	ll n = s.length();


	ll ans = 0;
	ll fr[10] = {0};
	for (int i = 0; i < n; i++)
	{
		fr[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) ans = max(ans, fr[i]);

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == j) continue;

			string d;
			for (int k = 0; k < n; k++)
			{
				ll ch = s[k] - '0';
				if (ch == i or ch == j)
				{
					d += s[k];
				}
			}
			d += "?";
			//cout << d << endl;
			ll len = 0;
			for (int k = 0; k < d.length() - 1; k++)
			{
				if (d[k] != d[k + 1]) len++;
			}
			if (len % 2 == 1) len--;
			ans = max(ans, len);
		}

	}

	cout << n - ans << endl;






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