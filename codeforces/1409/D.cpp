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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;
#define MAX 5


void solve(int t)
{
	ll n, s;
	cin >> n >> s;
	vector<ll> v;

	ll x = n;

	while (x > 0)
	{
		v.pb(x % 10);
		x /= 10;
	}
	v.pb(0);

	for (int i = 0; i < v.size() - 1; i++)
	{
		ll sum = 0;

		for (auto j : v) sum += j;

		if (sum <= s) break;

		if (sum > s)
		{
			if (v[i] != 0) v[i + 1]++;
			v[i] = 0;

		}

	}

	reverse(v.begin(), v.end());

	ll result = 0;


	for (auto i : v)
	{
		result = result * 10 + i;
	}

	//cout << result << " ";

	cout << result - n << endl;
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