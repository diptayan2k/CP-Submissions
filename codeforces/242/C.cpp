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
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

void solve(int t)
{
	ll x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	ll n;
	cin >> n;
	map<pair<ll, ll> , ll> allow, vis, lvl;

	for (int i = 0; i < n; i++)
	{
		ll r, a, b;
		cin >> r >> a >> b;
		for (int j = a; j <= b; j++)
			allow[ {r, j}] = 1;
	}

	queue<pair<ll, ll> > q;

	q.push({x0, y0});
	vis[ {x0, y0}] = 1;

	if (x0 == x1 and y0 == y1)
	{
		cout << 0 << endl;
		return;
	}

	while (!q.empty())
	{
		pair<ll, ll> u = q.front();
		q.pop();

		ll x = u.F;
		ll y = u.S;

		if (x > 1 and allow[ {x - 1, y}] == 1 and vis[ {x - 1, y}] == 0)
		{
			q.push({x - 1, y});
			vis[ {x - 1, y}] = 1;
			lvl[ {x - 1, y}] = lvl[u] + 1;
			if (x - 1 == x1 and y == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
		if (x < 1000000000 and allow[ {x + 1, y}] == 1 and vis[ {x + 1, y}] == 0)
		{
			q.push({x + 1, y});
			vis[ {x + 1, y}] = 1;
			lvl[ {x + 1, y}] = lvl[u] + 1;
			if (x + 1 == x1 and y == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
		if (y < 1000000000 and allow[ {x, y + 1}] == 1 and vis[ {x, y + 1}] == 0)
		{
			q.push({x, y + 1});
			vis[ {x, y + 1}] = 1;
			lvl[ {x, y + 1}] = lvl[u] + 1;
			if (x == x1 and y + 1 == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
		if (y > 1 and allow[ {x, y - 1}] == 1 and vis[ {x, y - 1}] == 0)
		{
			q.push({x, y - 1});
			vis[ {x, y - 1}] = 1;
			lvl[ {x, y - 1}] = lvl[u] + 1;
			if (x == x1 and y - 1 == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}


		if (x > 1 and y > 1 and  allow[ {x - 1, y - 1}] == 1 and vis[ {x - 1, y - 1}] == 0)
		{
			q.push({x - 1, y - 1});
			vis[ {x - 1, y - 1}] = 1;
			lvl[ {x - 1, y - 1}] = lvl[u] + 1;
			if (x - 1 == x1 and y - 1 == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
		if (x > 1 and y < 1000000000 and  allow[ {x - 1, y + 1}] == 1 and vis[ {x - 1, y + 1}] == 0)
		{
			q.push({x - 1, y + 1});
			vis[ {x - 1, y + 1}] = 1;
			lvl[ {x - 1, y + 1}] = lvl[u] + 1;
			if (x - 1 == x1 and y + 1 == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
		if (x < 1000000000 and y>1 and  allow[ {x + 1, y - 1}] == 1 and vis[ {x + 1, y - 1}] == 0)
		{
			q.push({x + 1, y - 1});
			vis[ {x + 1, y - 1}] = 1;
			lvl[ {x + 1, y - 1}] = lvl[u] + 1;
			if (x + 1 == x1 and y - 1 == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
		if (x < 1000000000 and y < 1000000000 and  allow[ {x + 1, y + 1}] == 1 and vis[ {x + 1, y + 1}] == 0)
		{
			q.push({x + 1, y + 1});
			vis[ {x + 1, y + 1}] = 1;
			lvl[ {x + 1, y + 1}] = lvl[u] + 1;
			if (x + 1 == x1 and y + 1 == y1)
			{
				cout << lvl[u] + 1 << endl;
				return;
			}
		}
	}

	cout << -1 << endl;






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

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}