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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	ll one = 0, zero = 0;
	vector<ll> v[2];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		v[b[i]].pb(a[i]);
		one += b[i];
	}
	zero = n - one;


	if (one == 0)
	{
		vector<ll> d = v[0];
		sort(d.begin(), d.end());
		if (d != v[0])
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
		return;

	}
	if (zero == 0)
	{
		vector<ll> d = v[1];
		sort(d.begin(), d.end());

		if (d != v[1])
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
		return;

	}

	cout << "Yes" << endl;

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