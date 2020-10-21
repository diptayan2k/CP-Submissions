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
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;

ll n, m, k;
vector<pair<ll, ll> > v[1001];

ll dis[1001];
ll shortest_path[1001][1001];

void dijkstra(ll src)
{
	for (ll i = 1; i <= n; i++) dis[i] = INF;
	dis[src] = 0;
	set<pair<ll, ll> > st;
	st.insert({0, src});

	while (!st.empty())
	{
		pair<ll, ll> tmp = *(st.begin());
		ll p = tmp.S;
		st.erase(st.begin());
		for (auto i : v[tmp.S])
		{
			ll u = i.F;
			ll wt = i.S;
			if (dis[u] > dis[p] + wt)
			{
				if (dis[u] != INF)
				{
					st.erase(st.find({dis[u], u}));
				}
				dis[u] = dis[p] + wt;
				st.insert({dis[u], u});


			}

		}
	}

	/*
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;*/
}

void solve(int t)
{
	cin >> n >> m >> k;

	pair<ll, ll> path[m];

	for (int i = 0; i < m; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		path[i].F = x;
		path[i].S = y;
		v[x].pb({y, w});
		v[y].pb({x, w});
	}

	pair<ll, ll> courier[k];

	for (int i = 0; i < k; i++)
	{
		cin >> courier[i].F;
		cin >> courier[i].S;
	}

	for (int i = 1; i <= n; i++)
	{
		dijkstra(i);
		for (int j = 1; j <= n; j++)
		{

			shortest_path[i][j] = dis[j];
			//cout << shortest_path[i][j] << " ";
		}
		//cout << endl;
	}



	ll ans = 0;

	for (int i = 0; i < k; i++)
	{
		ans += shortest_path[courier[i].F][courier[i].S];
	}



	for (int i = 0; i < m; i++)
	{
		ll x = path[i].F;
		ll y = path[i].S;

		ll tot = 0;

		//cout << x << " " << y << endl;

		for (int j = 0; j < k; j++)
		{
			ll p = courier[j].F;
			ll q = courier[j].S;

			tot += min({shortest_path[p][q], shortest_path[x][p] + shortest_path[q][y], shortest_path[x][q] + shortest_path[p][y]});
		}
		ans = min(ans, tot);

	}

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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}