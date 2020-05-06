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
using namespace std;
ll mod = 1000000007;
ll INF = 1000000000000000000;

void solve(int t)
{
	ll x, y;
	cin >> x >> y;
	if (x == 1 or y == 1)
	{
		cout << "YES" << endl;
		return;
	}
	if (x == 2 and y == 2)
	{
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;

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
