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
vector<ll> v[100001];
ll c[100001];
map<ll, ll> mm[100001];
ll fr[100001] = {0};

void solve(int t)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		fr[c[i]]++;
	}
	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	ll num = 0,  ma = -1;

	for (int i = 1; i <= n; i++)
	{

		for (auto j : v[i])
		{
			if (c[j] != c[i])
			{
				mm[c[i]][c[j]]++;
			}
		}

	}

	for (int i = 1; i <= 100000; i++)
	{
		if (mm[i].size() > ma and fr[i] > 0)
		{
			ma = mm[i].size();
			num = i;
		}
	}

	cout << num << endl;

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