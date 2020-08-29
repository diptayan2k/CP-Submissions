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
const int N = 18;

ll mp[10000001] = {0};
void solve(int t)
{
	ll n;
	cin >> n;

	ll a[n];

	for (int i = 1; i <= n * n + n; i++) mp[i] = 0;

	for (int i = 0; i < n; i++) cin >> a[i];


	ll ans = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		ll k = i + 1;

		for (int j = k + 1; j < n; j++)
		{
			mp[a[k]*n + a[j]]++;
		}
		for (int j = 0; j < i; j++)
		{
			ans += mp[a[j] * n + a[i]];
		}
	}

	cout << ans << endl;



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