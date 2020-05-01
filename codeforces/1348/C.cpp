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
using namespace std;
ll mod = 1000000007;
ll INF = 1000000000000000000;

bool cmp(string a, string b)
{
	return (a > b);
}

void solve(int t)
{
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;


	map<char, ll> fr;

	for (int i = 0; i < s.length(); i++)
	{
		fr[s[i]]++;
	}

	string p[k];
	string q = s;
	sort(q.begin(), q.end());
	if (k == 1)
	{
		cout << q << endl;
		return;
	}

	for (int i = 0; i < k; i++)
	{
		p[i] += q[i];
	}
	sort(p, p + k, cmp);

	/*
	for (int i = 0; i < k; i++)
	{
		cout << p[i] << endl;
	}
	cout << endl;*/
	int j;
	for (int i = k; i < n; i++)
	{
		if (q[i] != q[s.length() - 1])
		{
			p[k - 1] += q[i];
		}
		else
		{
			j = i;
			break;
		}
	}
	sort(p, p + k, cmp);

	/*for (int i = 0; i < k; i++)
	{
		cout << p[i] << endl;
	}
	cout << endl;*/

	string x[k], y[k];

	for (int i = 0; i < k; i++)
	{
		x[i] = p[i];
		y[i] = p[i];
	}

	for (int i = j; i < n; i++)
	{
		x[0] += q[i];
		y[k - 1] += q[i];
	}


	ll d = 0;
	for (int i = j; i < n; i++)
	{
		p[d++] += q[i];
		d %= k;
	}

	sort(x, x + k, cmp);
	sort(y, y + k, cmp);
	sort(p, p + k, cmp);
	/*
	for (int i = 0; i < k; i++)
	{
		cout << p[i] << " " << x[i] << " " << y[i] << endl;
	}*/
	//cout << endl;
	cout << min(p[0], min(x[0], y[0])) << endl;










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
