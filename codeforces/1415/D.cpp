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
	int a[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	if (n > 60)
	{
		cout << 1 << endl;
		return;
	}

	int pr[n + 1];
	pr[0] = 0;

	for (int i = 0; i < n; i++)
	{
		pr[i + 1] = pr[i] ^ a[i];
	}

	int ans = INF;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				int p = pr[j] ^ pr[i - 1];
				int q = pr[k] ^ pr[j];

				//cout << i << " " << j << " " << k << " " << p << " " << q << endl;

				if (p > q)
				{
					ans = min(ans, (j - i) + (k - j - 1));


				}

			}
		}
	}

	//cout << ans << endl;
	if (ans == INF)
		cout << -1 << endl;
	else cout << ans << endl;


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
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}