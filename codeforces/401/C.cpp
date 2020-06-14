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
	ll zero, one;
	cin >> zero >> one;
	ll n = zero + one;
	ll ans[3 * n];
	memset(ans, -1, sizeof(ans));
	ll cn[2] = {0};
	cn[0] = zero;
	cn[1] = one;
	//cout << cn[0] << " " << cn[1] << endl;
	ll last = -1, last_idx = -1;
	for (int i = 0, j = 0; cn[0] > 0 and cn[1] > 0; i += 2, j++)
	{
		j %= 2;
		cn[j]--;
		ans[i] = j;
		last = j;
		last_idx = i;

	}

	/*
	for (int i = 0; i < 3 * n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;*/
	//cout << cn[0] << " " << cn[1] << endl;
	if (cn[0] > 0)
	{
		if (cn[0] == 1 and last == 1 )
		{
			ans[last_idx + 2] = 0;
		}
		else
		{
			//cout << "hello" << endl;
			cout << -1 << endl;
			return;
		}
	}
	else if (cn[1] > 0)
	{
		ll flag = 0;

		for (int i = 1; i<3 * n and cn[1]>0 ; i++)
		{
			if (ans[i - 1] == 1 and flag == 0)
			{
				ans[i] = 1;
				cn[1]--;
				flag = 1;
				if (i > last_idx)
				{
					last_idx = i;
					last = 1;
				}
			}
			else flag = 0;
		}
	}

	if (cn[1] > 0)
	{
		//cout << cn[1] << endl;
		if (last == 0)
		{
			//cout << "hello" << endl;
			for (int j = 1; j <= min(cn[1], (ll)2); j++)
			{
				ans[last_idx + j] = 1;
				cn[1]--;
			}
			if (cn[1] <= 2)
			{
				if (cn[1] == 1) cout << 1;
				else if (cn[1] == 2) cout << 11;
			}
			else
			{
				cout << -1 << endl;
				return;
			}

		}
		else if (ans[last_idx] == 1 and ans[last_idx - 1] == 0)
		{
			ans[last_idx + 1] = 1;
			cn[1]--;
			if (cn[1] <= 2)
			{
				if (cn[1] == 1) cout << 1;
				else if (cn[1] == 2) cout << 11;
			}
			else
			{
				cout << -1 << endl;
				return;
			}

		}

	}

	for (int i = 0; i < 3 * n; i++)
	{
		if (ans[i] != -1) cout << ans[i];
	}

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