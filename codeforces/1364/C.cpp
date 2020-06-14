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
const int N = 100001;

ll tree[200005] = {0};

void update(ll val)
{
	for (int i = N + val; i > 0; i /= 2)
	{
		tree[i] += 1;
	}
}

ll query(ll l, ll r)
{
	ll sum = 0;
	for (l += N, r += N; l < r; l /= 2, r /= 2)
	{
		if (l % 2 == 1) sum += tree[l++];
		if (r % 2 == 1) sum += tree[--r];
	}

	return sum;

}

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];
	map<ll, ll> m, mm;
	for (int i = 0; i < n; i++) {cin >> a[i]; m[a[i]] = 1;}
	vector<ll> v;
	for (int i = 0; i <= 1000000; i++)
	{
		if (m[i] == 0) v.pb(i);
	}


	ll b[n];

	ll j = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > 0 and a[i] != a[i - 1]) b[i] = a[i - 1];
		else b[i] = v[j++];
		if (b[i] <= 100000)
		{
			update(b[i]);
		}
		if (query(0, a[i]) != a[i])
		{
			cout << -1 << endl;
			return ;
		}
	}



	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}


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