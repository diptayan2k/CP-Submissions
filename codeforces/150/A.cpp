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
	ll q;
	cin >> q;
	vector<ll> v;
	ll d = q;

	while (q % 2 == 0)
	{
		q /= 2;
		v.pb(2);
	}

	for (ll i = 3; i * i <= q; i += 2)
	{
		while (q % i == 0)
		{
			q /= i;
			v.pb(i);
		}
	}

	if (q > 2)
	{
		v.pb(q);
	}

	if (v.size() == 2)
	{
		cout << 2 << endl;
		return;
	}
	if (d == 1 or v.size() == 1)
	{
		cout << 1 << endl << 0 << endl;
		return;
	}
	cout << 1 << endl << v[0]*v[1] << endl;





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