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
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll d = k;
	bool vis[n] = {0};

	for (int j = 0; j < k; j++)
	{

		ll p = 0;
		ll q = 0;
		for (int i = j; i < n; i += d)
		{
			if (s[i] == '1') p++;
			if (s[i] == '0') q++;
		}

		if (p > 0 and q > 0)
		{
			cout << "NO" << endl;
			return;
		}
		for (int i = j; i < n; i += d)
		{
			if (s[i] == '?')
			{
				if (p > 0) s[i] = '1';
				else if (q > 0) s[i] = '0';
			}

		}
	}

	ll p = 0;
	ll q = k - 1;
	ll cnt0 = 0;
	ll cnt1 = 0;
	ll cnt = 0;

	//cout << s << endl;

	for (int i = 0; i < k; i++)
	{
		if (s[i] == '?') cnt++;
		if (s[i] == '0') cnt0++;
		if (s[i] == '1') cnt1++;
	}

	while (q < n)
	{
		if (cnt0 > k / 2 or cnt1 > k / 2)
		{
			cout << "NO" << endl;
			return;
		}
		if (s[p] == '1') cnt1--;
		if (s[p] == '0') cnt0--;
		if (s[p] == '?') cnt--;
		p++;
		q++;
		if (q < n)
		{
			if (s[q] == '1') cnt1++;
			if (s[q] == '0') cnt0++;
			if (s[q] == '?') cnt++;
		}
	}

	cout << "YES" << endl;


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