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
	string s, lol;
	ll k;
	cin >> s >> lol >> k;
	ll n = s.length();
	ll fr[n + 1] = {0};

	for (int i = 0; i < n; i++)
	{
		fr[i + 1] = abs(lol[s[i] - 'a'] - '1') + fr[i];
	}
	ll cnn = 0;
	vector<pair<ll, ll> > v;
	for (int i = 0; i < n; i++)
	{
		string p = s.substr(0, i + 1);
		reverse(p.begin(), p.end());
		ll len = i + 1;
		ll a[len];
		a[0] = 0;
		ll ma = 0;
		for (int j = 1; j < len; j++)
		{
			ll d = a[j - 1];
			while (d > 0 and p[d] != p[j])
			{
				d = a[d - 1];
			}
			if (p[d] == p[j])
				d++;
			a[j] = d;
			ma = max(ma, a[j]);

		}

		cnn += len - ma;
		for (int j = i - ma; j >= 0; j--)
		{
			v.pb({j, i});
		}
	}


	ll cn = 0;
	for (auto i : v)
	{

		ll l = i.F;
		ll r = i.S;

		if (fr[r + 1] - fr[l] <= k)
		{
			cn++;
		}
	}

	cout << cn << endl;


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