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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;


void solve(int t)
{
	ll n, m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++) cin >> s[i];
	vector<string> d;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 26; j++)
			d.pb(s[0].substr(0, i) + (char)(j + 'a') + s[0].substr(i + 1, m - i - 1));
	}

	for (auto i : d)
	{
		ll flag = 0;
		for (int j = 0; j < n; j++)
		{
			string p = s[j];
			ll cn = 0;
			for (int k = 0; k < m; k++)
			{
				if (s[j][k] != i[k])
				{
					cn++;
				}
			}
			if (cn > 1) flag = 1;
		}
		if (flag == 0)
		{
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;


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