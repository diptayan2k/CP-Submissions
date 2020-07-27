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
map<ll, ll> m;

vector<ll> v[100005];

void dfs(ll u, ll par)
{
	cout << m[u] << " ";

	for (auto i : v[u])
	{
		if (i == par) continue;
		dfs(i, u);
	}
}



void solve(int t)
{
	ll n;
	cin >> n;
	pair<ll, ll> p[n];
	map<ll, ll> mp;
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		p[i] = {x, y};
		mp[x]++;
		mp[y]++;

	}

	ll k = 1;

	for (auto i : mp)
	{
		//cout << i.F << " " << i.S << endl;
		mp[i.F] = k;
		m[k] = i.F;
		k++;
	}

	for (int i = 0; i < n; i++)
	{
		ll x = mp[p[i].F];
		ll y = mp[p[i].S];
		v[x].pb(y);
		v[y].pb(x);
	}

	/*
	for (auto i : mp)
	{
		cout << i.F << " " << i.S << endl;
	}*/




	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() == 1)
		{
			dfs(i, 0);
			break;
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