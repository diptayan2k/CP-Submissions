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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


void solve(int t)
{
	ll n, x;
	cin >> n >> x;
	ll a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll sum = 0;
	ll flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) flag = 1;
		sum += (a[i] - x);
	}



	sort(a, a + n);


	if (sum == 0)
	{
		if (a[0] == a[n - 1] and a[0] == x)
		{
			cout << 0 << endl;
			return;
		}
		cout << 1 << endl;
		return;
	}





	cout << 2 - flag << endl;


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