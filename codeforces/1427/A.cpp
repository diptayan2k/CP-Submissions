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


void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];

	ll sum = 0;
	vector<ll> pos, neg, zer;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		if (a[i] > 0) pos.pb(a[i]);
		else if (a[i] < 0) neg.pb(a[i]);
		else zer.pb(a[i]);
	}

	if (sum == 0)
	{
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;

	if (sum > 0)
	{
		for (auto i : pos) cout << i << " ";
		for (auto i : neg) cout << i << " ";
		for (auto i : zer) cout << i << " ";
		cout << endl;
		return;
	}

	if (sum < 0)
	{
		for (auto i : neg) cout << i << " ";
		for (auto i : pos) cout << i << " ";
		for (auto i : zer) cout << i << " ";
		cout << endl;
		return;
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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}