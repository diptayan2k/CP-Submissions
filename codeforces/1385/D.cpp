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
ll n;
string s;
ll fr[131073][26];
ll p;
 
ll foo(ll idx, ll k)
{
	if (k == 0)
	{
		if (s[idx] - 'a' == p)	return 0;
		else return 1;
	}
 
	
	ll len = (1ll << k);
	ll l1 = idx;
	ll r1 = idx + len / 2 - 1;
	ll diff1 = len / 2 - (fr[r1 + 1][p - k] - fr[l1][p - k]);
 
	ll l2 = idx + len / 2;
	ll r2 = idx + len - 1;
	ll diff2 = len / 2 - (fr[r2 + 1][p - k] - fr[l2][p - k]);
 
	ll res = INF;
 
 
	res = min(res, diff2 + foo(l1, k - 1));
	res = min(res, diff1 + foo(l2, k - 1));
 
	return res;
 
}
 
void solve(int t)
{
	cin >> n;
	cin >> s;
 
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			fr[i][j] = 0;
		}
		
	}
 
 
 
	for (int i = 0; i < 26; i++)
	{
		ll sum = 0;
		for (int j = 0; j < s.length(); j++)
		{
			if ((ll)(s[j] - 'a') == i)
			{
				sum++;
			}
			fr[j + 1][i] = sum;
		}
	}
	//cout << fr[3][0] - fr[1][0] << endl;
 
	p = log2(n);
 
	cout << foo(0, p) << endl;
 
 
 
 
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