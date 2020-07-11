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
map<ll, ll> fr;

void solve(int t)
{
	ll a;
	string s;
	cin >> a >> s;
	ll n = s.length();
	ll pre[n + 1];
	pre[0] = 0;
	for (int i = 0 ; i < n; i++)
	{
		pre[i + 1] = pre[i] + s[i] - '0';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i ; j <= n; j++)
		{
			fr[pre[j] - pre[i - 1]]++;
		}
	}

	ll ans = 0;
	if (a == 0)
	{
		for (int i = 0; i <= 40000; i++) ans += fr[0] * fr[i];
	}
	for (int i = 1 ; i <= 40000; i++)
	{
		if (a % i == 0 )
		{
			ll j = a / i;
			ans += fr[i] * fr[j];

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
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}