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

	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	ll z = 0;
	ll o = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) z++;
		else o++;
	}

	if (z >= n / 2)
	{
		cout << z << endl;

		for (int i = 0; i < z; i++)
		{
			cout << 0 << " ";
		}
		cout << endl;
		return;
	}

	else
	{


		cout << o - (o % 2) << endl;

		for (int i = 0; i < o - (o % 2); i++)
		{
			cout << 1 << " ";
		}
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