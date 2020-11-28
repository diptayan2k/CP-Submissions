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

ll n;
vector<ll> v[200001];
bool vis[200001];
bool cyc[200001];
ll cy;

void dfs(ll u, ll pa)
{
	vis[u] = true;

	for (auto i : v[u])
	{
		if (i == pa) continue;

		if (vis[i])
		{
			cy = u;
			continue;
		}

		dfs(i, u);
	}
}

vector<ll> cycle;
bool ok = 0;
void dfs1(ll u, ll pa)
{
	if (ok == 0) cycle.pb(u);
	//cout << u << " ";
	for (auto i : v[u])
	{
		if (i == pa) continue;
		if (i == cy)
		{
			ok = 1;
			continue;
		}
		dfs1(i, u);
	}
	if (ok == 0)
		cycle.pop_back();
}


ll cnt = 0;
void dfs2(ll u, ll pa)
{
	cnt++;
	for (auto i : v[u])
	{
		if (i == pa or cyc[i]) continue;
		dfs2(i, u);
	}

}


void solve(int t)
{
	ll n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		v[i].clear();
		vis[i] = false;
		cyc[i] = false;
	}




	for (int i = 1; i <= n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);

	//cout << cy << endl;
	ok = 0;
	dfs1(cy, 0);



	for (auto i : cycle)
	{
		cyc[i] = true;
		//cout << i << " ";
	}
	//cout << endl;

	ll sz = cycle.size();


	ll ans = 0;

	for (auto i : cycle)
	{
		cnt = 0;
		dfs2(i, 0);
		//cout << cnt << endl;

		ans += cnt * (n - cnt);
		ans += (cnt * (cnt - 1)) / 2;

	}

	cycle.clear();
	cout << ans << endl;


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