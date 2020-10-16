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


void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];
	ll sum = 0;

	ll b[n + 1];

	b[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += a[i - 1];
		b[i] = sum;
	}



	map<ll, ll> mp;

	ll ans = 0;
	mp[0]++;
	for (int i = 1; i <= n; i++)
	{
		if (mp[b[i]] != 0)
		{
			ans++;
			mp.clear();
			mp[b[i - 1]]++;
		}
		mp[b[i]]++;
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