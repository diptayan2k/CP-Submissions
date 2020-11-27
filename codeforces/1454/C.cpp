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
const ll mod1 = 1000000007;
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	vector<ll> v[n + 1];

	for (int i = 1; i <= n; i++)
	{
		v[i].pb(-1);
	}

	for (int i = 0; i < n; i++)
	{
		v[a[i]].pb(i);
	}

	for (int i = 1; i <= n; i++)
	{
		v[i].pb(n);
	}


	ll ans = INF;
	for (int i = 1; i <= n; i++)
	{

		if (v[i].size() == 2) continue;

		ll cnt = 0;
		for (int j = 1; j < v[i].size(); j++)
		{
			if (v[i][j] - v[i][j - 1] > 1) cnt++;
		}

		ans = min(ans, cnt);
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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}