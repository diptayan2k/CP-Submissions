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

const ll MAXN = 10000001;
int spf[MAXN];
map<ll, ll> mp;
vector<ll> v;
map<ll, ll> fra, frb;
bool pr[MAXN];


void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)


		spf[i] = i;


	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++)
	{

		if (spf[i] == i)
		{
			for (int j = i * i; j < MAXN; j += i)

				if (spf[j] == j)
					spf[j] = i;
		}
	}
}


void solve(int t)
{

	sieve();
	//memset(prime, true, sizeof(prime));

	for (int i = 2; i < MAXN; i++)
	{
		if (!pr[spf[i]]) {
			v.pb(spf[i]);
			pr[spf[i]] = true;
		}

	}

	//for (int i = 2; i < MAXN; i++) if (prime[i]) v.pb(i);
	ll n, m;
	cin >> n >> m;
	ll a[n], b[m];

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		ll x = a[i];
		while (x != 1)
		{
			fra[(spf[x])]++;
			x = x / spf[x];
		}
	}
	for (int i = 0; i < m; i++)
	{
		ll x = b[i];
		while (x != 1)
		{
			frb[(spf[x])]++;
			x = x / spf[x];
		}
	}

	for (auto i : v)
	{
		ll x = min(fra[i], frb[i]);
		fra[i] -= x;
		frb[i] -= x;
	}


	vector<ll> ans1, ans2;
	for (int i = 0; i < n; i++)
	{
		ll x = a[i];
		ll d = 1;
		while (x != 1)
		{

			if (fra[(spf[x])] > 0)
			{
				d *= spf[x];
				fra[spf[x]]--;
			}
			x = x / spf[x];
		}
		ans1.pb(d);
	}
	for (int i = 0; i < m; i++)
	{
		ll x = b[i];
		ll d = 1;
		while (x != 1)
		{

			if (frb[(spf[x])] > 0)
			{
				d *= spf[x];
				frb[spf[x]]--;
			}
			x = x / spf[x];
		}
		ans2.pb(d);
	}


	cout << ans1.size() << " " << ans2.size() << endl;

	for (auto i : ans1) cout << i << " ";
	cout << endl;
	for (auto i : ans2) cout << i << " ";
	cout << endl;

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