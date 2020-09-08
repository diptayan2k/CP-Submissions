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


void solve(int t)
{
	ll n;
	cin >> n;

	vector<ll> ans(n, 0);
	stack<ll> st;
	st.push(1);
	ll a[n + 1] = {0};
	for (int i = 2; i <= n; i++)
	{
		ll x , y;
		ll idx = st.top();
		st.pop();

		cout << "? " << i << " " << idx << endl;
		cout.flush();
		cin >> x;

		cout << "? " << idx << " " << i << endl;
		cout.flush();
		cin >> y;


		if (x > y)
		{
			ans[i - 1] = x;
			a[x] = 1;
			st.push(idx);

		}
		else
		{
			ans[idx - 1] = y;
			a[y] = 1;
			st.push(i);
		}

	}

	ll d = -1;

	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0) d = i;
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 0) ans[i] = d;
	}

	cout << "! ";
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;
	cout.flush();
	ll xx;
	cin >> xx;

	if (xx == -1) exit(0);




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