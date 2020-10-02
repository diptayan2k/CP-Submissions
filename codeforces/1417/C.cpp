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
const ll mod = 998244353;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{

	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	map<ll, ll> mp, mpp;

	ll k = 0;
	for (int i = 0; i < n; i++)
	{
		if (mp[a[i]] == 0)
		{
			mp[a[i]] = ++k;
			mpp[k] = a[i];
		}
	}

	vector<ll> v[k + 1];

	for (int i = 1; i <= k; i++)	v[i].pb(-1);

	for (int i = 0; i < n; i++)
	{
		v[mp[a[i]]].pb(i);
	}

	for (int i = 1; i <= k; i++)	v[i].pb(n);





	vector<ll> ans(n + 1, -1);

	for (int i = k; i >= 1; i--)
	{
		ll ma  = -1;


		for (int j = 1; j < v[i].size(); j++)
		{
			ma = max(ma, v[i][j] - v[i][j - 1]);
		}

		if (ans[ma] != -1) ans[ma] = min(ans[ma], mpp[i]);
		else ans[ma] = mpp[i];

	}

	ll num = -1;
	for (int i = 1; i <= n; i++)
	{
		if (num != -1 and ans[i] != -1)
		{
			ans[i] = min(ans[i], num);
			num = ans[i];
		}
		if (num == -1 and ans[i] != -1) num = ans[i];
		if (ans[i] == -1 and num != -1) ans[i] = num;

	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}

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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}