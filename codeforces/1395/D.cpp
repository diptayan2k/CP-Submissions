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

ll n, d, m;
ll a[100005];
ll pr[100005];
ll idx;

void solve(int t)
{

	cin >> n >> d >> m;

	for (int i = 0; i < n; i++) cin >> a[i];


	ll ma = 0;
	for (int i = 0; i < n; i++) ma = max(ma, a[i]);



	vector<ll> big, small;

	small.pb(0);
	big.pb(0);

	for (int i = 0; i < n; i++)
	{
		if (a[i] > m) big.pb(a[i]);
		else small.pb(a[i]);
	}


	sort(big.begin() + 1, big.end(), greater<ll>());
	sort(small.begin() + 1, small.end(), greater<ll>());

	ll b = big.size() - 1;
	ll s = small.size() - 1;

	for (int i = 1; i <= b; i++)
	{
		big[i] += big[i - 1];
	}

	for (int i = 1 ; i <= s; i++)
	{
		small[i] += small[i - 1];
	}


	if (b == 0)
	{
		ll sum = 0;
		for (int i = 0; i < n; i++) sum += a[i];
		cout << sum << endl;
		return;
	}



	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		small.pb(small[s]);
	}
	ans = 0;
	for (int i = (b + d) / (1 + d) ; i <= b; i++)
	{
		ll x = i;
		ll y = (x - 1) * (d + 1) + 1;
		ll z = n - y;

		if ( y <= n)
		{
			ans = max(ans, big[i] + small[z]);
		}


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