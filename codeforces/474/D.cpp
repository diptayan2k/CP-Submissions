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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;
ll k;
ll a[100001] = {0};
ll b[100001] = {0};
void solve(int t)
{
	ll x, y;
	cin >> x >> y;
	cout << (b[y] - b[x - 1]+mod) % mod << endl;
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
	cin >> t >> k;

	for (int i = 0; i < k; i++) a[i] = 1;
	for (int i = k; i <= 100000; i++) a[i] = (a[i - k] + a[i - 1]) % mod;
	b[0] = a[0];

	for (int i = 1; i <= 100000; i++ ) b[i] = (a[i] + b[i - 1]) % mod;


	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}