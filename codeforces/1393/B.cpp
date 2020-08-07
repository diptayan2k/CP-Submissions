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
const int d = (1ll << N);
ll F[d];



void solve(int t)
{
	ll n;
	cin >> n;

	ll a[n];

	map<ll, ll> m;
	set<pair<ll, ll> > st;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		m[a[i]]++;
	}

	for (auto i : m)
	{
		st.insert({i.S, i.F});
	}

	ll q;
	cin >> q;
	//cout << q << endl;

	while (q--)
	{
		//cout << q << endl;
		char ch;
		ll x;
		cin >> ch >> x;
		ll old = m[x];
		if (ch == '+') m[x]++;
		else m[x]--;

		if (st.find({old, x}) != st.end())
		{
			st.erase(st.find({old, x}));

		}
                st.insert({m[x], x});

		vector<ll> v;
		auto it = st.end();
		if (st.size() >= 1)
		{
			it--;
			v.pb((*it).F);
		}
		if (st.size() >= 2)
		{
			it--;
			v.pb((*it).F);
		}
		if (st.size() >= 3)
		{
			it--;
			v.pb((*it).F);
		}
		if (v.empty())
		{
			cout << "NO" << endl;
			continue;
		}
		if (v[0] < 4)
		{
			cout << "NO" << endl;
			continue;
		}
		v[0] -= 4;

		ll flag = 0;

		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] >= 4)
			{
				flag = 1;
				break;
			}
		}

		for (int j = 0; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				if (v[j] >= 2 and v[k] >= 2)
				{
					flag = 1;
					break;
				}
			}
		}

		if (flag == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}










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
	//cin >> t;


	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}