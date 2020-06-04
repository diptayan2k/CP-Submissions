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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;


void solve(int t)
{
	ll n;
	cin >> n;
	ll mat[n + 1][n + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> mat[i][j];
		}
	}
	ll a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll dis[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) dis[i][j] = INF;

	for (int i = 1; i <= n; i++) dis[i][i] = 0;

	vector<ll> v;
	ll flag[n + 1] = {0};
	for (int k = n; k > 0; k--)
	{
		ll d = a[k];
		flag[d] = 1;
		for (int i = 1; i <= n; i++)
		{
			dis[d][i] = min(mat[d][i], dis[d][i]);
			dis[i][d] = min(mat[i][d], dis[i][d]);
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][d] + dis[d][j]);
				if (flag[i] and flag[j]) ans += dis[i][j];
			}
		}
		v.pb(ans);
	}

	reverse(v.begin(), v.end());
	for (auto i : v) cout << i << " ";
	cout << endl;



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