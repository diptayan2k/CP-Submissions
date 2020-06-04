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
#define op1(x) cout<<"Scenario #"<<x<<": "
using namespace std;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;
ll n, m;
ll a[500001];
vector<ll> v[500001];

bool cmp(ll x , ll y)
{
	if (a[x] < a[y]) return true;

	return false;
}


void solve(int t)
{
	cin >> n >> m;
	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		set<ll> s;
		for (auto j : v[i])
		{
			if (a[i] == a[j])
			{
				cout << "-1" << endl;
				return;
			}

			if (a[j] < a[i]) s.insert(a[j]);

		}
		//cout << "HELLO" << endl;
		if (!s.empty()) {
			ll d = s.size();
			ll p = *(s.begin());
			auto itr = s.end();
			itr--;
			ll q = *itr;
			if (abs(q - p + 1) != d or d != a[i] - 1)
			{
				cout << -1 << endl;
				return;
			}
		}
	}
	//cout << "HELLO" << endl;


	ll b[n + 1];
	for (int i = 1; i <= n; i++) b[i] = i;

	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		cout << b[i] << " ";
	}
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
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}