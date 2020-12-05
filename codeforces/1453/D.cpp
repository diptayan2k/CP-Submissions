#include <iostream>
#include<bits/stdc++.h>
#define int long long int
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
const int mod1 = 1000000007;
const int mod = 998244353;
const int INF = 1000000000000000000;//LLONG_MAX;
const int NEGINF = LLONG_MIN;
const int N = 18;
const int MAXN = 1000001;

void solve(int t)
{

	int n;
	cin >> n;

	if (n % 2 == 1)
	{
		cout << -1 << endl;
		return;
	}
	if (n == 2)
	{
		cout << 1 << endl << 1 << endl;
		return;
	}

	vector<int> v;

	while (v.size() < 2000)
	{
		int x = 2;
		int sum = 2;
		v.pb(1);
		while (sum <= n)
		{
			x *= 2;
			sum += x;
			if (sum > n)
			{
				sum -= x;
				break;
			}
			else
			{
				v.pb(0);
			}
		}

		n -= sum;

		if (n % 2 == 1 or n == 0) break;

	}

	
		cout << v.size() << endl;
		for (auto i : v) cout << i << " ";
		cout << endl;
	



}


#undef int
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