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
const ll mod1 = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;





void solve(int t)
{

	ll n;
	cin >> n;
	string s;
	cin >> s;

	string p = "", q = "";

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			p += "0";
			q += "1";
		}
		else
		{
			p += "1";
			q += "0";
		}

	}

	ll a[n + 1] = {0}, b[n + 1] = {0};

	for (int i = 0; i < n; i++)
	{
		if (s[i] != p[i]) a[i] = 1;
		if (s[i] != q[i]) b[i] = 1;
	}

	ll cnt1 = 0, cnt2 = 0;
	ll ans = INF;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1] and a[i - 1] == 1) cnt1++;
		if (b[i] != b[i - 1] and b[i - 1] == 1) cnt2++;
	}

	cout << min(cnt1, cnt2) << endl;



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