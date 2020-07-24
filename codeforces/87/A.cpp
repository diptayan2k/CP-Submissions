
// Problem : A. Trains
// Contest : Codeforces - Codeforces Beta Round #73 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/87/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

ll power(ll x, ll y)
{
	if (y == 0) return 1;
	ll q = power(x, y / 2) % mod;
	if (y % 2 == 0)
		return (q * q) % mod;
	else
		return ((q * q) % mod * x) % mod;
}

void solve(int t)
{

	ll a,b;
	cin>>a>>b;
	ll d = (a*b)/__gcd(a,b);
	ll p = d/a - 1;
	ll q = d/b - 1;

	if(a>b) p++;
	else q++;
	
	if(p>q)
	{
		cout<<"Dasha"<<endl;
	}
	else if(p<q)
	{
		cout<<"Masha"<<endl;
	}
	else
	{
		cout<<"Equal"<<endl;
	}
	

}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}