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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;
string s;
string d;
ll n;
ll a[100001];
map<char, ll> m;
ll dp[100001][5];


ll foo(ll i, ll len)
{
	if (i == n)
	{
		if (len == 4) return INF;
		return 0;
	}

	if (dp[i][len] != -1) return dp[i][len];

	ll res = INF;

	if (m[s[i]] == len + 1)
	{
		res = min(res, foo(i + 1, len + 1));
	}
	else
		res = min(res, foo(i + 1, len));


	if (m[s[i]] != 0)
		res = min(res, a[i] + foo(i + 1, len));

	return dp[i][len] = res;


}

void solve(int t)
{
	cin >> n;
	cin >> s;
	d = s;
	for (int i = 0; i < n; i++) cin >> a[i];

	m['h'] = 1;
	m['a'] = 2;
	m['r'] = 3;
	m['d'] = 4;

	memset(dp, -1, sizeof(dp));

	cout << foo(0, 0) << endl;





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