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
using namespace std;
ll mod = 1000000007;
ll INF = 1000000000000000000;

void solve(int t)
{
	ll n;
	cin >> n;
	ll cn = 0;
	while (n > 0)
	{
		ll p = (sqrt(24 * n + 1) - 1) / 6;

		if (p > 0 )
		{
			ll q = (p * (3 * p + 1) / 2);
			//cout << n << " " << q << endl;
			if (n >= q)
			{
				n -= q;
				cn++;
			}
		}
		if (n < 2)
		{
			break;
		}

	}
	cout << cn << endl;

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
