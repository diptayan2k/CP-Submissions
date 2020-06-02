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
ll n, m;
vector<ll> v[3001];
ll gr[3001][3001];


void solve(int t)
{
	cin >> n >> m;
	memset(gr, 0, sizeof(gr));
	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		gr[x][y] = 1;
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{

			if (j != i)
			{
				ll cn = 0;
				for (auto k : v[i])
				{
					if (gr[k][j] == 1) cn++;
				}
				ans += (cn * (cn - 1)) / 2;
			}
		}
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