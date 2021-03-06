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
const ll mod = 998244353;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


void solve(int t)
{
	ll n;
	cin >> n;

	string s;
	cin >> s;

	ll odd[2] = {0};
	ll even[2] = {0};

	for (int i = 0; i < n; i += 2)
	{
		odd[(s[i] - '0') % 2]++;
	}
	for (int i = 1; i < n; i += 2)
	{
		even[(s[i] - '0') % 2]++;
	}

	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 1)
		{
			if (odd[0] > 0) odd[0]--;
			else odd[1]--;
		}
		else
		{
			if (even[1] > 0) even[1]--;
			else even[0]--;
		}
	}

	if (odd[0] > 0 or even[0] > 0) cout << 2 << endl;
	else cout << 1 << endl;


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