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
const ll INF = 1e18;
const int N = 18;


void solve(int t)
{

	ll n, k , l;
	cin >> n >> k >> l;

	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		if (a[i] > l)
		{
			cout << "No" << endl;
			return;
		}

	}

	ll safe[n] = {0};
	ll time = k;
	for (int i = 0; i < n; i++)
	{
		if (a[i] + k <= l) safe[i] = 1;
	}

	time = k + 1;

	for (int i = 0; i < n; i++)
	{
		//cout << time << endl;
		time %= (2 * k);
		//cout << time << endl;
		if (safe[i] == 1) time = k;
		else
		{
			if (time > k)
			{
				ll depth = 2 * k - time;
				if (a[i] + depth > l )
				{
					time = 2 * k - min((l - a[i]), k);
				}
				time %= (2 * k);
			}

			else if (time < k)
			{
				ll depth = time;
				if (a[i] + depth > l)
				{
					cout << "No" << endl;
					return;
				}
			}
			else
			{
				if (safe[i] == 0)
				{
					cout << "No" << endl;
					return;
				}

			}
		}
		//cout << time << endl;
		time++;
	}

	cout << "Yes" << endl;


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