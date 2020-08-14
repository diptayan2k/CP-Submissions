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
const int N = 18;
#define mul(x,y) x*y

ll dp[1000000][10];


void solve(int t)
{

	string s;
	ll n;
	cin >> n;
	cin >> s;
	//ll n = s.length();
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = s[i] - '0' - 1;
	}

	ll sum = 0;


	for (int i = 1; i < n; i++)
	{
		//cout << a[i] << " ";
		a[i] += a[i - 1];
	}

	map<ll, ll> mp;

	ll ans  = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			ans += mp[a[i]] + 1;
			mp[a[i]]++;

		}
		else
		{
			ans += mp[a[i]];
			mp[a[i]]++;
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