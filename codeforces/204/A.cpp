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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;
vector<ll> v;
ll dp[19][10][10][2];

ll foo(ll idx, ll first, ll curr, ll tight)
{
	if (idx == -1)
	{
		return (first == curr);
	}

	if (dp[idx][first][curr][tight] != -1)
		return dp[idx][first][curr][tight];

	ll res = 0;

	ll k = (tight) ? v[idx] : 9;

	for (int i = 0; i <= k ; i++)
	{

		ll newTight = (v[idx] == i) ? tight : 0;


		res += foo(idx - 1, (first == 0) ? i : first, i , newTight);
	}



	return dp[idx][first][curr][tight] = res;

}

ll getans(ll x)
{
	if (x == 0)
	{
		return 1;
	}
	while (x != 0)
	{
		v.pb(x % 10);
		x /= 10;
	}

	memset(dp, -1, sizeof(dp));


	ll d = foo(v.size() - 1, 0, 0, 1);
	v.clear();
	return d;
}

void solve(int t)
{
	//cout << getans(0) << endl;
	ll l, r;
	cin >> l >> r;
	cout << getans(r) - getans(l - 1) << endl;


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