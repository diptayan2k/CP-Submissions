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
#define mul(x,y) x*y

ll n, d, m;
ll a[100005];
ll pr[100005];
ll idx;

void solve(int t)
{

	string s;
	cin >> s;
	vector<ll> v;
	s += "0";
	ll cnt = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1') cnt++;
		else
		{
			if (cnt > 0)
			{
				v.pb(cnt);
				cnt = 0;
			}
		}
	}

	sort(v.begin(), v.end(), greater<ll>());

	ll ans = 0;
	for (int i = 0; i < v.size(); i += 2) ans += v[i];

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