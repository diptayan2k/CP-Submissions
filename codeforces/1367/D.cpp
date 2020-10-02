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
const ll mod = 998244353;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{

	string s;
	cin >> s;
	ll m;
	cin >> m;
	ll b[m];
	for (int i = 0; i < m; i++) cin >> b[i];
	map<char, int> mp;
	for (auto i : s) mp[i]++;
	vector<char> v;
	for (auto i : mp) v.pb(i.F);
	reverse(v.begin(), v.end());

	char ans[m];
	int d = 0;

	ll mark[m] = {0};

	while (true)
	{
		bool flag = 0;

		vector<ll> ma;
		ll cnt = 0;

		for (int i = 0; i < m; i++) if (b[i] == 0 and mark[i] == 0) cnt++;

		while (mp[v[d]] < cnt)
		{
			d++;
		}

		for (int i = 0; i < m; i++)
		{
			if (b[i] == 0 and mark[i] == 0)
			{
				ma.pb(i);
				ans[i] = v[d];
				mark[i] = 1;
			}
			else if (b[i] > 0) flag = 1;
		}

		/*
		for (int i = 0; i < m; i++)
		{
			cout << b[i] << " ";
		}
		cout << endl;*/

		if (flag == 0) break;

		for (int i = 0; i < m; i++)
		{
			ll sum = 0;
			for (auto k : ma)
			{
				sum += abs(k - i);
			}
			if (mark[i] == 0) b[i] -= sum;
		}
		d++;
	}


	for (int i = 0; i < m; i++)
		cout << ans[i];
	cout << endl;

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