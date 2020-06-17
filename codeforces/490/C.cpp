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
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;


void solve(int t)
{
	string s;
	cin >> s;
	ll a, b;
	cin >> a >> b;
	ll n = s.length();
	ll pr[n + 1] = {0}, sf[n + 1] = {0};
	ll power[n + 1];
	power[0] = 1;
	for (int i = 1; i <= n; i++) power[i] = (power[i - 1] * 10) % b;

	for (int i = 1; i <= n; i++)
	{
		pr[i] = ((pr[i - 1] * 10) % mod + (s[i - 1] - '0')) % a;
	}
	sf[n] = (s[n - 1] - '0') % b;
	for (int i = n - 1; i >= 1; i--)
		sf[i] = ((power[n - i] * (ll)(s[i - 1] - '0')) % b + sf[i + 1]) % b;

	for (int i = 1; i < n; i++)
	{
		if (pr[i] == 0 and sf[i + 1] == 0 and s[i] != '0')
		{

			cout << "YES" << endl;
			cout << s.substr(0, i) << endl;
			cout << s.substr(i, n - i) << endl;
			return;
		}
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
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}