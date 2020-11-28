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
const ll mod1 = 1000000007;
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


ll query(ll l, ll r, ll tree[], ll n)
{

	ll res = INF;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, tree[l++]);
		if (r & 1) res = min(res, tree[--r]);
	}
	return res;

}

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];

	ll tree[2 * n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tree[n + i] = a[i];
	}

	for (int i = n - 1; i > 0; i--) tree[i] = min(tree[2 * i], tree[2 * i + 1]);

	ll p[n], q[n];

	p[0] = a[0];
	q[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++)
	{
		p[i] = max(p[i - 1], a[i]);
	}

	for (int i = n - 2; i >= 0; i--)
	{
		q[i] = max(q[i + 1], a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int j = lower_bound(q + i + 2, q + n, p[i], greater<ll>()) - q;
		if (q[j] != p[i]) continue;
		if (query(i + 1, j, tree, n) == p[i])
		{
			cout << "YES" << endl << i + 1 << " " << j - i - 1 << " " << n - j << endl;
			return;
		}

		j++;
		if (j < n and q[j] == q[j - 1] and query(i + 1, j, tree, n) == p[i])
		{
			cout << "YES" << endl << i + 1 << " " << j - i - 1 << " " << n - j << endl;
			return;
		}
	}



	cout << "NO" << endl;








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