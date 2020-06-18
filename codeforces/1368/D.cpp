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
const int N = 20;
ll F[(1ll << 20) + 1];
ll A[(1ll << 20) + 1] = {0};
void solve(int t)
{
	ll n;

	cin >> n;

	ll a[n + 1];
	ll fr[25] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j <= 20; j++)
		{
			ll d = (1ll << j);
			if ((d & a[i]) != 0) fr[j]++;
		}
	}
	//for (int i = 0; i < 20; i++) cout << fr[i] << " ";
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll d = 0;
		for (int j = 0; j < 21; j++)
		{
			if (fr[j] > 0)
			{
				d |= (1ll << j);
				fr[j]--;
			}
		}

		sum += d * d;

	}
	cout << sum << endl;

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