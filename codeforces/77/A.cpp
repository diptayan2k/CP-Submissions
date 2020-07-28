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
const int N = 20;

ll n;
map<string, ll> m;
map<pair<ll, ll>, ll  > mp;

ll ass[7];

ll p, q, r;

ll maxi(ll lol1, ll lol2, ll lol3)
{
	return max(max(lol1, lol2), lol3);
}

ll mini(ll lol1, ll lol2, ll lol3)
{
	return min(min(lol1, lol2), lol3);
}

pair<ll, ll> foo(ll idx, ll a, ll b, ll c)
{

	if (idx == 7)
	{
		if (a == 0 or b == 0 or c == 0) return { INF, -INF};
		ll cn = 0;
		for (ll i = 0; i < 7; i++)
		{
			for (ll j = 0; j < 7; j++)
			{
				if (ass[i] == ass[j] and mp[ {i, j}] == 1 and i != j) cn++;
			}
		}
		ll ma1 = maxi(p / a, q / b, r / c);
		ll mi1 = mini(p / a, q / b, r / c);


		ll num = ma1 - mi1;

		return {num, cn};

	}

	pair<ll, ll> res = {INF, -INF};
	pair<ll, ll> d;

	ass[idx] = 1;
	d = (res, foo(idx + 1, a + 1, b, c));
	if (d.F < res.F)
	{
		res = d;
	}
	else if (d.F == res.F and d.S > res.S)
	{
		res = d;
	}

	ass[idx] = 2;
	d = (res, foo(idx + 1, a, b + 1, c));
	if (d.F < res.F)
	{
		res = d;
	}
	else if (d.F == res.F and d.S > res.S)
	{
		res = d;
	}

	ass[idx] = 3;
	d = (res, foo(idx + 1, a, b, c + 1));
	if (d.F < res.F)
	{
		res = d;
	}
	else if (d.F == res.F and d.S > res.S)
	{
		res = d;
	}

	return res;

}


void solve(int t)
{
	string s[7] = {"Anka",  "Chapay",  "Cleo",  "Troll",  "Dracul", "Snowy" , "Hexadecimal"};

	for (int i = 0; i < 7; i++) m[s[i]] = i;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string x, y, z;
		cin >> x >> y >> z;
		//cout << m[x] << " " << m[z] << endl;
		mp[ {m[x], m[z]}] = 1;
	}
	/*
	for (auto i : mp)
	{
		cout << i.F.F << " " << i.F.S << endl;
	}*/
	cin >> p >> q >> r;

	pair<ll, ll> ans = foo(0, 0, 0, 0);
	cout << ans.F << " " << ans.S << endl;



}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}