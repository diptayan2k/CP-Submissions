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
const ll mod1 = 1000000007;
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{

	ll n, k;
	cin >> n >> k;
	ll a[n], b[k];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];

	ll pos[n + 1] = {0};
	ll appear[n + 1] = {0};

	for (int i = 0; i < n; i++)
	{
		pos[a[i]] = i;
	}

	for (int i = 0; i < k; i++)
	{
		appear[b[i]] = i;
	}

	ll ans = 1;

	for (int i = 0; i < k; i++)
	{
		ll idx = pos[b[i]];
		ll mul = 2;

		if (idx == 0 or idx == n - 1) mul--;
		if (idx > 0 and appear[a[idx - 1]] > i) mul--;
		if (idx < n - 1 and appear[a[idx + 1]] > i) mul--;

		ans = (ans * mul) % mod;
	}

	cout << ans % mod << endl;







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