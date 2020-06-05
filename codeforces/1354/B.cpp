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
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 21;


void solve(int t)
{
	string s;
	cin >> s;
	ll n = s.length();
	ll fr[3][n + 1];
	memset(fr, 0, sizeof(fr));
	ll sum[3] = {0};
	for (int i = 0; i < n; i++)
	{
		sum[s[i] - '1']++;

		for (int j = 0; j < 3; j++)
			fr[j][i + 1] = sum[j];
	}


	ll lo = 3;
	ll hi = n;
	ll ans = 0;
	ll mid;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;

		bool flag = false;
		for (int i = 0; i + mid - 1 < n; i++)
		{
			if ((fr[0][i + mid] - fr[0][i]) != 0 and (fr[1][i + mid] - fr[1][i]) != 0 and (fr[2][i + mid] - fr[2][i]) != 0)
			{
				flag = true;
				break;
			}

		}

		if (flag)
		{
			hi = mid - 1;
			ans = mid;
		}
		else
		{
			lo = mid + 1;
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
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}