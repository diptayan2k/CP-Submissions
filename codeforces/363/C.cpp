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
	string s;
	cin >> s;

	string a;
	for (int i = 0; i < s.length(); i++)
	{
		if (i >= 2 and s[i - 1] == s[i] and s[i - 2] == s[i]) continue;
		a += s[i];
	}

	string ans;
	for (int i = 0; i < a.length(); i++)
	{

		if (i < a.length() - 3ll and a[i] == a[i + 1] and a[i + 2] == a[i + 3])
		{
			//cout << i << " " << a.length() - 3 << endl;
			ans += a[i];
			ans += a[i + 1];
			ans += a[i + 2];
			i = i + 3;

		}
		else
		{
			ans += a[i];
		}
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
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}