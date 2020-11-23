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
const ll mod1 = 1000000007;
const ll mod = 998244353;
const ll INF = 1000000000000000000;//LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;



void solve(int t)
{

	ll n;
	cin >> n;

	ll a[n];

	for (int i = 2; i <= n; i++)
	{
		cout << "XOR 1 " << i << endl;
		cout.flush();
		cin >> a[i - 1];
	}

	ll aandc, aandb, bandc;
	cout << "AND 1 2" << endl;
	cout.flush();
	cin >> aandb;

	cout << "AND 1 3" << endl;
	cout.flush();
	cin >> aandc;

	cout << "AND 2 3" << endl;
	cout.flush();
	cin >> bandc;

	ll axorb = a[1];
	ll axorc = a[2];
	ll bxorc = a[1] ^ a[2];

	ll smab = axorb + 2 * aandb;
	ll smac = axorc + 2 * aandc;
	ll smbc = bxorc + 2 * bandc;

	ll dfac = smab - smbc;

	a[0] = (smac + dfac) / 2;

	for (int i = 1; i < n; i++)
	{
		a[i] ^= a[0];
	}

	cout << "! ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout.flush();






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