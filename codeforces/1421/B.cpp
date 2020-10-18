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
	string s[n];

	for (int i = 0; i < n; i++) cin >> s[i];

	vector<char> v, v1, v2;

	vector<pair<ll, ll> > d;
	v.pb(s[0][1]);
	v.pb(s[1][0]);
	v.pb(s[0][2]);
	v.pb(s[1][1]);
	v.pb(s[2][0]);


	d.pb({0, 1});
	d.pb({1, 0});
	d.pb({0, 2});
	d.pb({1, 1});
	d.pb({2, 0});

	v1.pb('0');
	v1.pb('0');
	v1.pb('1');
	v1.pb('1');
	v1.pb('1');

	v2.pb('1');
	v2.pb('1');
	v2.pb('0');
	v2.pb('0');
	v2.pb('0');

	ll cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != v1[i]) cnt1++;
		if (v[i] != v2[i]) cnt2++;
	}

	//cout << cnt1 << " " << cnt2 << endl;

	if (cnt1 <= 2)
	{
		cout << cnt1 << endl;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != v1[i])
			{
				cout << d[i].F + 1 << " " << d[i].S + 1 << endl;
			}
		}
		return;
	}

	if (cnt2 <= 2)
	{
		cout << cnt2 << endl;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != v2[i])
			{
				cout << d[i].F + 1 << " " << d[i].S + 1 << endl;
			}
		}
		return;
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