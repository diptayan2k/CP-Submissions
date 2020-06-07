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
const int N = 21;
ll b[2000001];

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	ll maxi = 0;
	set<ll> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
		maxi = max(maxi, a[i]);
	}

	sort(a, a + n);


	for (int i = 1; i <= 2 * maxi; i++)
	{
		ll lo = 0;
		ll hi = n - 1;
		ll mid;
		ll ans = -1;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;

			if (a[mid] < i)
			{
				lo = mid + 1;
				ans = a[mid];
			}
			else
			{
				hi = mid - 1;
			}
		}
		b[i] = ans;
	}

	ll modval = 0;
	for (auto i : s)
	{
		for (int j = 2 * i; j <= 2 * maxi; j += i)
		{
			if (b[j] != -1)
				modval = max(modval, b[j] % i);
		}

	}

	cout << modval << endl;

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