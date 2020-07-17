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


void solve(int t)
{
	ll n;
	cin >> n;
	string s[n];
	char s1[n][n];

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s1[i][j] = s[j][i];
		}
	}

	ll a[n] = {0}, b[n] = {0};

	ll suma = 0, sumb = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '.') a[i] = 1;
			if (s1[i][j] == '.') b[i] = 1;
		}
		suma += a[i];
		sumb += b[i];
	}

	if (suma < n and sumb < n)
	{
		cout << -1 << endl;
		return;
	}

	if (suma == n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (s[i][j] == '.')
				{
					cout << i + 1 << " " << j + 1 << endl;
					break;
				}
			}
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s1[i][j] == '.')
			{
				cout << j + 1 << " " << i + 1 << endl;
				break;
			}
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