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
const ll mod = 1000000009;
const ll INF = 1e18;
const int N = 20;

void solve(int t)
{
	string s;

	cin >> s;
	ll one = 0, zero = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1') one++;
		else zero++;
	}

	ll d = min(one, zero);

	if (d % 2 == 0)
	{
		cout << "NET" << endl;
		return;
	}
	cout << "DA" << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}