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
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

void solve(int t)
{
	ll n, w;
	cin >> n >> w;

	pair<ll, ll> a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].F;
		a[i].S = i + 1;
	}



	sort(a, a + n);

	ll sum = 0;

	vector<ll> v;
	for (int i = n - 1; i >= 0; i--)
	{
		if (sum + a[i].F <= w)
		{
			sum += a[i].F;
			v.pb(a[i].S);
		}

	}

	ll d = w / 2 + (w % 2);

	if (sum < d)
	{
		cout << -1 << endl;
		return;
	}

	cout << v.size() << endl;
	for (auto i : v) cout << i << " ";

	cout << endl;





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