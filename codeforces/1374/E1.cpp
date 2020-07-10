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
	ll n, k;
	cin >> n >> k;
	vector<ll> alice, bob, both;

	for (int i = 0; i < n; i++)
	{
		ll tt, x, y;
		cin >> tt >> x >> y;
		if (x == 1 and y == 1)
		{
			both.pb(tt);
		}
		else if (x == 1 and y == 0)
		{
			alice.pb(tt);
		}
		else if (x == 0 and y == 1)
		{
			bob.pb(tt);
		}
	}

	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	sort(both.begin(), both.end());


	ll a = alice.size();
	ll b = bob.size();
	ll c = both.size();

	ll p = 0;
	ll q = 0;
	ll r = 0;
	ll sum = 0;

	while (p < a and q < b and r<c and k>0)
	{
		if (both[r] < alice[p] + bob[q])
		{
			sum += both[r];
			r++;
			k--;
		}
		else
		{
			sum += alice[p] + bob[q];
			p++;
			q++;
			k--;
		}
	}

	while (r<c and k>0)
	{
		sum += both[r];
		r++;
		k--;
	}

	while ( p < a and q < b and k > 0)
	{	sum += alice[p] + bob[q];
		p++;
		q++;
		k--;
	}

	if (k > 0)
	{
		cout << - 1 << endl;
		return;
	}
	else
	{
		cout << sum << endl;
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