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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

ll n, m, k;
string s[501];
ll maxi[501][502];
ll num[501];
ll dp[501][501];

ll foo(ll idx, ll cnt)
{
	if (cnt > k) return INF;
	if (idx == n) return 0;

	if (dp[idx][cnt] != -1) return dp[idx][cnt];

	ll res = INF;
	for (int i = 0; i <= m; i++)
	{
		res = min(res, i + foo(idx + 1, cnt + num[idx] - maxi[idx][i]));
	}

	return dp[idx][cnt] = res;
}


void solve(int t)
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++)
	{
		maxi[i][0] = 0;
		for (int j = 1; j <= m; j++)
		{
			ll window = 0;
			for (int l = 0; l < j; l++) window += s[i][l] - '0';
			int p = 0;
			int q = j - 1;
			ll an = 0;
			while (q < m)
			{
				an = max(an, window);
				window -= (s[i][p] - '0');
				p++;
				q++;
				if (q == m) break;
				window += (s[i][q] - '0');
			}
			maxi[i][j] = an;
		}
	}

	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
		for (int j = 0; j < m; j++)
		{
			num[i] += (s[i][j] - '0');
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << foo(0, 0) << endl;

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