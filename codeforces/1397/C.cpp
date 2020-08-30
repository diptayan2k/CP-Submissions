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

ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll p = power(x, y / 2);
	p = (p * p) ;

	return (y % 2 == 0) ? p : (x * p);
}


void solve(int t)
{

	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	if (n == 1)
	{
		cout << "1 1" << endl << -a[0] << endl;
		a[0] = 0;
		cout << "1 1" << endl << -a[0] << endl;
		cout << "1 1" << endl << -a[0] << endl;
		return;
	}

	cout << 1 << " " << n - 1 << endl;

	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i]*(n - 1) << " ";
		a[i] += a[i] * (n - 1);
	}
	cout << endl;
	cout << n << " " << n << endl;
	cout << -a[n - 1] << endl;
	a[n - 1] = 0;

	cout << 1 << " " << n << endl;

	for (int i = 0; i < n; i++)
	{
		if (i < n)
			cout << -1 * a[i] << " ";

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