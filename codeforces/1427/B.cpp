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

	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	/*
	ll idx = -1;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
	{
		cout << max(2 * k - 1, 0ll) << endl;
		return;
	}
	*/


	ll prev = -1;
	ll a[n] = {0};

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{

			a[i] = prev;
			prev = i;
		}
	}

	vector<vector<ll> > v;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W' and a[i] != -1)
		{
			if (i - a[i] - 1 > 0)
				v.pb({i - a[i] - 1, a[i] + 1, i - 1});
		}
	}

	sort(v.begin(), v.end());

	for (auto i : v)
	{
		for (int j = i[1]; j <= i[2] and k > 0; j++)
		{
			s[j] = 'W';
			k--;
		}
	}

	ll flag = 0;

	//cout << k << " " << s << endl;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W') flag = 1;
		if (s[i] == 'L' and flag == 1 and k > 0)
		{
			s[i] = 'W';
			flag = 1;
			k--;
		}

	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (k > 0 and s[i] == 'L')
		{
			s[i] = 'W';
			k--;
		}
	}

	flag = 0;
	ll ans = 0;

	//cout << s << endl;

	if (s[0] == 'W')
	{
		ans++;
		flag = 1;
	}

	for (int i = 1; i < n; i++)
	{
		if (s[i] == 'W')
		{
			ans += (1 + flag);
			flag = 1;
		}
		else flag = 0;
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
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}