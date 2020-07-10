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

	ll n, k;
	cin >> n >> k;
	ll a[n];
	map<ll, ll> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % k == 0) continue;
		a[i] = k - (a[i] % k);
		m[a[i]]++;
	}

	vector<pair<ll, ll> > p;
	for (auto i : m)
	{
		p.pb({i.S, i.F});
	}
	sort(p.begin(), p.end());

	if (p.empty())
	{
		cout << 0 << endl;
		return;
	}
	pair<ll, ll> v;
	auto itr = p.end();
	itr--;
	v = *(itr);
	//cout << v.F << " " << v.S << endl;

	cout << (v.F - 1)*k + v.S + 1 << endl;

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