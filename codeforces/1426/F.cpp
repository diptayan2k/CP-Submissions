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
ll n;
string s;
ll tot = 0;


ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll p = power(x, y / 2) % mod;
	p = (p % mod * p % mod) % mod;

	return (y % 2 == 0) ? p % mod : (x % mod * p % mod) % mod;
}

ll dp[200001][4][4];

ll foo(ll idx, ll cnt, ll ques)
{

	if (ques > 3 or cnt > 3) return 0;
	if (idx == n)
	{
		if (cnt == 3)
		{
			return power(3, (tot - ques)) % mod;
		}
		return 0;
	}

	if (dp[idx][cnt][ques] != -1) return dp[idx][cnt][ques] % mod;

	ll res = 0;

	if (s[idx] == 'a' and cnt == 0)
		res = (res % mod + foo(idx + 1, cnt + 1, ques) % mod) % mod;

	if (s[idx] == 'b' and cnt == 1)
		res = (res % mod + foo(idx + 1, cnt + 1, ques) % mod) % mod;

	if (s[idx] == 'c' and cnt == 2)
		res = (res % mod + foo(idx + 1, cnt + 1, ques) % mod) % mod;

	if (s[idx] == '?')
		res = (res % mod + foo(idx + 1, cnt + 1, ques + 1) % mod) % mod;


	res = (res % mod + foo(idx + 1, cnt, ques) % mod) % mod;


	dp[idx][cnt][ques] = res % mod;
	return dp[idx][cnt][ques];
}


void solve(int t)
{

	cin >> n;
	cin >> s;

	for (auto i : s) if (i == '?') tot++;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			for (int k = 0; k <= 3; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}


	cout << foo(0, 0, 0) % mod << endl;


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