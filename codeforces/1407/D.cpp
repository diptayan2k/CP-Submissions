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
#define MAX 5

vector<ll> v[300001];

void solve(int t)
{
	ll n;
	cin >> n;
	ll a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	stack<ll> st;

	vector<ll> nextgr(n, -1);
	vector<ll> prevgr(n, -1);
	vector<ll> nextsm(n, -1);
	vector<ll> prevsm(n, -1);

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() and a[st.top()] < a[i])
		{
			st.pop();
		}
		if (!st.empty())
		{
			prevgr[i] = st.top();
		}

		st.push(i);
	}


	while (!st.empty()) st.pop();


	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() and a[st.top()] < a[i])
		{
			st.pop();
		}
		if (!st.empty())
		{
			nextgr[i] = st.top();
		}

		st.push(i);
	}

	while (!st.empty()) st.pop();

	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() and a[st.top()] > a[i])
		{
			st.pop();
		}
		if (!st.empty())
		{
			nextsm[i] = st.top();
		}

		st.push(i);
	}


	while (!st.empty()) st.pop();

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() and a[st.top()] > a[i])
		{
			st.pop();
		}
		if (!st.empty())
		{
			prevsm[i] = st.top();
		}

		st.push(i);
	}



	for (int i = 0; i < n - 1; i++)
		v[i].pb(i + 1);

	for (int i = 0; i < n; i++)
	{
		if (prevsm[i] != -1)
			v[prevsm[i]].pb(i);
		if (nextsm[i] != -1)
			v[i].pb(nextsm[i]);
		if (prevgr[i] != -1)
			v[prevgr[i]].pb(i);
		if (nextgr[i] != -1)
			v[i].pb(nextgr[i]);

	}


	queue<ll> q;
	bool vis[n];
	memset(vis, false, sizeof(vis));
	q.push(0);
	vis[0] = true;
	ll lev[n] = {0};
	lev[0] = 0;



	while (!q.empty())
	{
		ll u = q.front();
		q.pop();

		for (auto i : v[u])
		{
			if (!vis[i])
			{
				vis[i] = true;
				lev[i] = lev[u] + 1;
				if (i == n - 1)
				{
					cout << lev[n - 1] << endl;
					return;
				}
				q.push(i);
			}
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