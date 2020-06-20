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
	ll n;
	cin >> n;
	if (n == 1)
	{
		cout << "FastestFinger" << endl;
		return;
	}
	if (n == 2)
	{
		cout << "Ashishgup" << endl;
		return;
	}
	if (n % 2 == 1)
	{
		cout << "Ashishgup" << endl;
		return;
	}

	vector<ll> v;
	ll x = n;

	while (n % 2 == 0)
	{
		n /= 2;
		v.pb(2);
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			n /= i;
			v.pb(i);
		}
	}
	if (n > 2) v.pb(n);

	ll odd = 0;
	ll pd = 1;
	for (auto i : v) if (i % 2 == 1) {odd++; pd *= i;}
	if (odd == 0)
	{
		cout << "FastestFinger" << endl;
		return;
	}
	if ((x / pd) == 2 and odd == 1)
	{
		cout << "FastestFinger" << endl;
		return;
	}
	cout << "Ashishgup" << endl;

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