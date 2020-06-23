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


void solve(int t)
{
	//cout << "Hello" << endl;
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	ll b[k];
	for (int i = 0; i < k; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + k, greater<ll>());

	vector<ll> s[k];
	ll sum1 = 0, sum2 = 0;
	ll j = 0;

	for (int i = 0; i < k; i++)
	{
		while (b[i] > 1)
		{
			s[i].pb(a[j++]);
			b[i]--;
		}
		sort(s[i].begin(), s[i].end());
		/*
		for (auto m : s[i])
		{
			cout << m << " ";
		}
		cout << endl;*/
	}

	//cout << j << endl;

	ll l = n - 1;
	for (int i = 0; i < k; i++)
	{
		if (s[i].empty())
		{
			sum1 += (2 * a[j++]);
			sum2 += (2 * a[l--]);
		}
		else
		{
			sum1 += (s[i][0] + a[j++]);
			sum2 += (s[i][0] + a[l--]);

		}
	}

	cout << max(sum1, sum2) << endl;




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