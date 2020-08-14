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
#define mul(x,y) x*y


ll r, g, b;
ll red[201], green[201], blue[201];
ll dp[201][201][201];

ll foo(ll idxa, ll idxb, ll idxc )
{

	if (dp[idxa][idxb][idxc] != -1) return dp[idxa][idxb][idxc];

	ll res = 0;

	if (idxa < r and idxb < g)
		res = max(res, red[idxa] * green[idxb] + foo(idxa + 1, idxb + 1, idxc));
	if (idxa < r and idxc < b)
		res = max(res, red[idxa] * blue[idxc] + foo(idxa + 1, idxb, idxc + 1));
	if (idxc < b and idxb < g)
		res = max(res, blue[idxc] * green[idxb] + foo(idxa, idxb + 1, idxc + 1));

	return dp[idxa][idxb][idxc] = res;

}


void solve(int t)
{


	cin >> r >> g >> b;



	for (int i = 0; i < r; i++)
	{
		cin >> red[i];
	}

	for (int i = 0; i < g; i++)
	{
		cin >> green[i];
	}


	for (int i = 0; i < b; i++)
	{
		cin >> blue[i];
	}

	sort(red, red + r, greater<ll>());
	sort(green, green + g, greater<ll>());
	sort(blue, blue + b, greater<ll>());

	memset(dp, -1, sizeof(dp));

	cout << foo(0, 0, 0) << endl;












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