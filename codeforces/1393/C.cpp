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
const int N = 18;




void solve(int t)
{

	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	map<ll, ll> m;

	for (int i = 0; i < n; i++) m[a[i]]++;
	ll ma = 0;
	ll num = -1;

	for (auto i : m)
	{
		if (i.S >= ma)
		{
			ma = i.S;
			num = i.F;
		}
	}



	ll sum = 0;
	for (auto i : m )
	{
		if (i.F != num)
		{
			sum += min(i.S, ma - 1);
		}
	}

	cout << sum / (ma - 1) << endl;









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