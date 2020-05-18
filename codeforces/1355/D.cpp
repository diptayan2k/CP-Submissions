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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
const ll mod = 1e9 + 7;


void solve(int t)
{
	int n, s;
	cin >> n >> s;
	ll d = s / n;
	vector<ll> v;
	for (int i = 0; i < n; i++)
	{
		v.pb(d);
	}
	ll q = s % n;
	v[n - 1] += (q);
	//for (auto i : v) cout << i << " ";
	vector<ll> v1;
	ll sum = 0;
	for (int i = n - 1; i > 0; i--)
	{
		sum += v[i];
		v1.pb(sum);
	}
	ll ans = -1;
	for (int i = 1; i <= s / 2; i++)
	{
		if (i % d != 0 and find(v1.begin(), v1.end(), i) == v1.end() and find(v1.begin(), v1.end(), s - i) == v1.end())
		{
			ans = i;
			break;
		}
	}
	if (ans == -1)
	{
		cout << "NO" << endl;
		return;
	}
	else
	{
		cout << "YES" << endl;
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl << ans << endl;
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