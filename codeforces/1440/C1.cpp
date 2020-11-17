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
const ll mod1 = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


ll n, m;
string s[5001];
int a[1001][1001];
vector< vector<pair<ll, ll> > > ans;

bool foo(ll x, ll y)
{

	vector<pair<ll, ll> > z, o;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[x + i][y + j] == 0) z.pb({x + i, y + j});
			else o.pb({x + i, y + j});
		}
	}

	vector<pair<ll, ll> > v;

	//cout << o.size() << " " << z.size() << endl;




	if (o.size() == 2 or o.size() == 1)
	{
		for (int i = 0; i < 1; i++)
		{
			v.pb(o[i]);
			ll xx = o[i].F;
			ll yy = o[i].S;
			a[xx][yy] ^= 1;
		}

		for (int i = 0; i < 2; i++)
		{
			v.pb(z[i]);
			ll xx = z[i].F;
			ll yy = z[i].S;
			a[xx][yy] ^= 1;
		}
	}


	else if (o.size() == 3 or o.size() == 4)
	{
		for (int i = 0; i < 3; i++)
		{
			v.pb(o[i]);
			ll xx = o[i].F;
			ll yy = o[i].S;
			a[xx][yy] ^= 1;
		}
	}

	if (!v.empty()) ans.pb(v);
	v.clear();
	z.clear();
	o.clear();


	ll cn = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[x + i][y + j] == 1) cn++;
		}
	}

	if (cn == 0) return true;

	return false;






}


void solve(int t)
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[i][j] - '0';
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			while (!foo(i, j));
		}
	}


	cout << ans.size() << endl;

	for (auto i : ans)
	{
		for (auto j : i)
		{
			cout << j.F + 1 << " " << j.S + 1 << " ";
		}

		if (!i.empty()) cout << endl;
	}

	ans.clear();



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