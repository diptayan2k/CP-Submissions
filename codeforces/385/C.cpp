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
const int N = 20;

vector<ll> pr;
bool prime[10000000 + 1];
vector<ll> v[1000001];
ll m[10000001];
ll fr[1000001];
ll pre[1000001];
ll freq[10000001] = {0};

void solve(int t)
{
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= 10000000; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= 10000000; i += p)
				prime[i] = false;
		}
	}

	for (int i = 2; i <= 10000000; i++)
	{
		if (prime[i]) {pr.pb(i); m[i] = pr.size();}

	}

	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
	}

	for (auto i : pr)
	{

		for (int j = i; j <= 10000000; j += i)
		{
			fr[m[i]] += freq[j];
		}
	}

	pre[0] = 0;

	for (int i = 0; i < pr.size(); i++)
	{
		pre[i + 1] = fr[i + 1] + pre[i];
	}

	ll q;
	cin >> q;
	while (q--)
	{
		ll l, r;
		cin >> l >> r;

		ll x = lower_bound(pr.begin(), pr.end(), l) - pr.begin();
		ll y = upper_bound(pr.begin(), pr.end(), r) - pr.begin();
		cout << pre[y] - pre[x] << endl;

	}





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