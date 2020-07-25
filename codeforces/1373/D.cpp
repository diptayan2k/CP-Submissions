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

ll maxSubArraySum(vector<ll> a)
{
	ll size = a.size();
	ll max_so_far = -INF, max_ending_here = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2 == 0) sum += a[i];
	}

	ll b[n];
	vector<ll> v1, v2;
	for (int i = 0; i < n - 1; i += 2)
	{
		v1.pb(a[i + 1] - a[i]);
		//sum += a[i];
	}

	for (int i = 1; i < n - 1; i += 2)
	{
		v2.pb(a[i] - a[i + 1]);
	}
	//ll d = maxSubArraySum(v1);
	//cout << d << endl;
	ll d = max(maxSubArraySum(v1), maxSubArraySum(v2));
	if (d > 0)
	{
		cout << d + sum << endl;
		return;
	}
	cout << sum << endl;



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