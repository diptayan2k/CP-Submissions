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

	ll ar[n];
	map<ll, ll> mp;

	for (int i = 0; i < n; i++) cin >> ar[i];

	for (auto i : ar) mp[i]++;

	vector<ll> a, b;
	map<ll, ll> mpa, mpb;
	for (int i = 0; i <= 100; i++)
	{
		if (mp[i] > 1)
		{
			a.pb(i);
			b.pb(i);
			mpa[i]++;
			mpb[i]++;
		}
		if (mp[i] == 1)
		{
			mpa[i]++;
			a.pb(i);
		}
	}

	ll ans = 0;

	for (int i = 0; i <= 100; i++)
	{
		if (mpa[i] == 0) {ans += i; break;}
	}
	for (int i = 0; i <= 100; i++)
	{
		if (mpb[i] == 0) {ans += i; break;}
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