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
ll n;

ll foo(ll cnt, ll rocka, ll scissora, ll papera, ll rockb, ll scissorb, ll paperb)
{
	if (cnt >= n) return 0;

	ll p = INF, q = INF, r = INF, s = INF, t = INF, u = INF, v = INF, w = INF, x = INF;

	if (min(rocka, rockb) > 0)
		p = foo(cnt + min(rocka, rockb) , rocka - min(rocka, rockb), scissora, papera, rockb - min(rocka, rockb), scissorb, paperb);
	if (min(rocka, paperb) > 0)
		q = foo(cnt + min(rocka, paperb) , rocka - min(rocka, paperb), scissora, papera, rockb, scissorb, paperb - min(rocka, paperb));
	if (min(rocka, scissorb) > 0)
		r = min(rocka, scissorb) + foo(cnt + min(rocka, scissorb) , rocka - min(rocka, scissorb), scissora, papera, rockb, scissorb - min(rocka, scissorb), paperb);

	if (min(papera, rockb) > 0)
		s = min(papera, rockb) + foo(cnt + min(papera, rockb) , rocka, scissora, papera - min(papera, rockb), rockb - min(papera, rockb), scissorb, paperb);
	if (min(papera, paperb) > 0)
		t = foo(cnt + min(papera, paperb) , rocka, scissora, papera - min(papera, paperb), rockb, scissorb, paperb - min(papera, paperb));
	if (min(papera, scissorb) > 0)
		u = foo(cnt + min(papera, scissorb) , rocka, scissora, papera - min(papera, scissorb), rockb, scissorb - min(papera, scissorb), paperb);

	if (min(scissora, rockb) > 0)
		v = foo(cnt + min(scissora, rockb) , rocka, scissora - min(scissora, rockb), papera, rockb - min(scissora, rockb), scissorb, paperb);
	if (min(scissora, paperb) > 0)
		w = min(scissora, paperb) + foo(cnt + min(scissora, paperb) , rocka, scissora - min(scissora, paperb), papera, rockb, scissorb, paperb - min(scissora, paperb));
	if (min(scissora, scissorb) > 0)
		x = foo(cnt + min(scissora, scissorb) , rocka, scissora - min(scissora, scissorb), papera, rockb, scissorb - min(scissora, scissorb), paperb);

	ll res = min({p, q, r, s, t, u, v, w, x});

	return res;
}

void solve(int t)
{

	cin >> n;
	ll rocka, scissora, papera, rockb, scissorb, paperb;

	cin >> rocka >> scissora >> papera;
	cin >> rockb >> scissorb >> paperb;

	ll p = min(scissora, rockb + scissorb);
	ll q = min(rocka, paperb + rocka);
	ll r = min(papera, scissorb + papera);

	cout << foo(0, rocka, scissora, papera, rockb, scissorb, paperb) << " ";
	cout << min(rocka, scissorb) + min(scissora, paperb) + min(papera, rockb) << endl;

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