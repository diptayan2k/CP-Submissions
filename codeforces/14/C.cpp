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



void solve(int t)
{
	ll x1[4], x2[4], y1[4], y2[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	map<pair<ll, ll>, ll > mp;
	for (int i = 0; i < 4; i++)
	{
		mp[ {x1[i], y1[i]}]++;
		mp[ {x2[i], y2[i]}]++;
	}

	if (mp.size() != 4)
	{
		cout << "NO" << endl;
		return;
	}

	for (auto i : mp)
	{
		if (i.S != 2)
		{
			cout << "NO" << endl;
			return;
		}
	}
	ll a = 0;
	ll b = 0;

	for (int i = 0; i < 4; i++)
	{
		if (x1[i] == x2[i] and y1[i] == y2[i])
		{
			cout << "NO" << endl;
			return;
		}
		if (x1[i] == x2[i]) a++;
		if (y1[i] == y2[i]) b++;
	}

	if (a != 2 or b != 2 )
	{
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;





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