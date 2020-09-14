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
	ll a[n];
	ll lock[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> lock[i];

	vector<ll> v;

	for (int i = 0; i < n; i++)
	{
		if (lock[i] == 0) v.pb(a[i]);
	}


	vector<int> ans;
	ll pr = 0;

	sort(v.begin(), v.end(), greater<ll>());

	//for (auto i : v)  cout << i << " ";



	ll k = 0;
	for (int i = 0; i < n; i++)
	{
		if (lock[i])
		{
			ans.pb(a[i]);
		}
		else
		{
			ans.pb(v[k++]);
		}

	}

	for (auto i : ans)
		cout << i << " ";

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