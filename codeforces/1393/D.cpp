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

ll n, m;
ll lvl[2001][2001];
string s[2001];




void solve(int t)
{
	cin >> n >> m;
	ll ans = 0;

	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i >= 2 and j >= 1 and j < m - 1 and s[i - 2][j] == s[i][j] and s[i - 1][j] == s[i][j] and s[i - 1][j - 1] == s[i][j] and s[i - 1][j + 1] == s[i][j])
			{
				lvl[i][j] = min({lvl[i - 2][j], lvl[i - 1][j], lvl[i - 1][j - 1] , lvl[i - 1][j + 1]}) + 1;
			}
			else lvl[i][j] = 1;
			ans += lvl[i][j];

			//cout << lvl[i][j] << " ";
		}
		//cout << endl;
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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}