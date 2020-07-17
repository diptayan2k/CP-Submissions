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

	string s[7];
	s[0] = "1869";
	s[1] = "1968";
	s[2] = "1689";
	s[3] = "6198";
	s[4] = "8691";
	s[5] = "1986";
	s[6] = "1896";

	string num;
	cin >> num;
	ll fr[10] = {0};

	for (int i = 0; i < num.length(); i++)
	{
		fr[num[i] - '0']++;
	}

	fr[1]--;
	fr[6]--;
	fr[8]--;
	fr[9]--;

	string ans;


	for (int i = 9; i > 0; i--)
	{
		while (fr[i]--)
		{
			ans += (char)('0' + i);
		}
	}
	//cout << ans << endl;

	ll m = 0;

	for (int i = 0; i < ans.length(); i++)
	{
		m = (m * 10 + (ans[i] - '0')) % 7;
	}
	m %= 7;
	m *= 10000;
	m %= 7;


	ans += s[(7 - m) % 7];

	while (fr[0]--) ans += "0";
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