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
const int N = 20;





void solve(int t)
{
	ll n;
	cin >> n;
	ll s = 6 + 10 + 14;

	if (n == 36)
	{
		cout << "YES" << endl;
		cout << "5 6 10 15" << endl;
		return;
	}
	if (n == 44)
	{
		cout << "YES" << endl;
		cout << "6 7 10 21" << endl;
		return;
	}
	if (n == 40)
	{
		cout << "YES" << endl;
		cout << "6 22 10 2" << endl;
		return;
	}


	if (n > s)
	{
		cout << "YES" << endl;
		cout << 6 << " " << 10 << " " << 14 << " " << n - s << endl;
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