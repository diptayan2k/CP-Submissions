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
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;

void solve(int t)
{
	string s;
	cin >> s;
	ll n = s.length();
	ll pi[n];
	pi[0] = 0;

	for (int i = 1; i < n; i++)
	{
		ll j = pi[i - 1];
		while (j > 0 and s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}



	ll len = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (pi[i] == pi[n - 1])
		{
			len = max(len, pi[i]);
		}
		else if (pi[i] == pi[pi[n - 1] - 1])
		{
			len = max(len, pi[i]);
		}

	}

	if (len == 0)
	{
		cout << "Just a legend" << endl;
		return;
	}
	cout << s.substr(0, len) << endl;



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