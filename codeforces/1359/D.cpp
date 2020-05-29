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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
const ll mod = 998244353;
const ll INF = 1e18;
const int N = 21;
ll n;
ll a[100001], pre[200001], suf[200001], sum[200001];
ll next_greater[100001], prev_greater[100001];

ll querys(ll l , ll r)
{
	vector<ll> v1, v2;
	for (l += n, r += n; l < r; l /= 2, r /= 2)
	{
		if (l % 2 == 1) v1.pb(l++);
		if (r % 2 == 1) v2.pb(--r);
	}
	reverse(v2.begin(), v2.end());
	ll res = 0;
	ll prev = -1 * INF;

	for (auto i : v2)
	{
		v1.pb(i);
	}
	reverse(v1.begin(), v1.end());

	prev = 0;
	for (auto i : v1)
	{
		res = max(res, max(prev + suf[i], prev));
		prev += sum[i];

	}

	return res;
}

ll queryp(ll l , ll r)
{
	vector<ll> v1, v2;
	for (l += n, r += n; l < r; l /= 2, r /= 2)
	{
		if (l % 2 == 1) v1.pb(l++);
		if (r % 2 == 1) v2.pb(--r);
	}
	reverse(v2.begin(), v2.end());
	ll res = 0;
	ll prev = -1 * INF;

	for (auto i : v2)
	{
		v1.pb(i);
	}

	prev = 0;
	for (auto i : v1)
	{
		res = max(res, max(prev + pre[i], prev));
		prev += sum[i];
	}

	return res;
}



void solve(int t)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pre[n + i] = a[i];
		suf[n + i] = a[i];
		sum[n + i] = a[i];
	}

	stack<ll> st;
	for (int i = 0; i < n; i++) next_greater[i] = n;
	memset(prev_greater, -1, sizeof(prev_greater));

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() and a[st.top()] < a[i])
		{
			ll u = st.top();
			st.pop();
			next_greater[u] = i;
		}
		st.push(i);
	}

	while (!st.empty()) st.pop();

	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() and a[st.top()] < a[i])
		{
			ll u = st.top();
			st.pop();
			prev_greater[u] = i;
		}
		st.push(i);
	}


	for (int i = n - 1; i > 0; i--)
	{
		sum[i] = sum[2 * i] + sum[2 * i + 1];
		pre[i] = max(pre[2 * i], sum[2 * i] + pre[2 * i + 1]);
		suf[i] = max(suf[2 * i + 1], sum[2 * i + 1] + suf[2 * i]);
	}


	ll ans = -INF;



	for (int i = 0; i < n; i++)
	{
		ll p = next_greater[i];
		ll q = prev_greater[i];
		ll d = max(querys(q + 1, i) + queryp(i + 1, p), 0ll);
		ans = max(ans, d);

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