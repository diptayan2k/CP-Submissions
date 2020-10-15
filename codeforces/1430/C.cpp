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
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

void solve(int t)
{
	ll n;
	cin >> n;
	priority_queue<ll> pq;

	for (int i = 1; i <= n; i++) pq.push(i);

	vector<pair<ll, ll> > v;
	while (pq.size() > 1)
	{
		ll x = pq.top();
		pq.pop();
		ll y = pq.top();
		pq.pop();
		ll z = (x + y) / 2 + (x + y) % 2;
		pq.push(z);
		v.pb({x, y});
	}

	cout << pq.top() << endl;

	for (auto i : v)
	{
		cout << i.F << " " << i.S << endl;
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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}