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

ll check(vector<ll> a, vector<ll> b)
{
	ll n = a.size();
	ll m = b.size();
	ll i = 0;
	ll j = 0;

	ll sz = 0;
	ll last = -1;
	while (i < n and j < m)
	{
		if (a[i] < b[j] and i < n)
		{
			while (a[i] < b[j] and i < n)
			{
				i++;
			}
			sz++;
			last = 0;
		}

		if ((b[j] < a[i] and j < m))
		{
			while (b[j] < a[i] and j < m)
			{
				j++;
			}
			sz++;
			last = 1;
		}
	}

	if (i < n and (last == 1 or last == -1))
	{
		sz++;

	}
	if (j < m and (last == 0 or last == -1))
	{
		sz++;
	}



	return sz;
}

void solve(int t)
{

	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	map<ll, ll> mp;

	for (int i = 0; i < n; i++)
	{
		if (mp[a[i]] == 0)
		{
			mp[a[i]] = 1;

		}
	}

	ll k = 0;
	vector<ll> d;

	for (auto i : mp)
	{
		mp[i.F] = k++;
		d.pb(i.F);
	}
	for (int i = 0; i < n; i++) a[i] = mp[a[i]];

	k = mp.size();

	vector<ll> v[k];

	for (int i = 0; i < n; i++) v[a[i]].pb(i);

	ll ans = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = i; j < k; j++)
		{
			if (i != j)
			{
				ans = max(check(v[i], v[j]), ans);

			}
			else
			{
				ll len = v[i].size();
				ans = max(len, ans);
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