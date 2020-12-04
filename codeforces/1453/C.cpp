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

int area(int x1, int y1, int x2, int y2, int n)
{

	int ans = 0;
	if (x1 == x2)
	{
		int base = abs(y1 - y2);
		int height = max(x1, n - 1 - x1);
		ans = max(ans, base * height);
	}

	if (y1 == y2)
	{
		int base = abs(x1 - x2);
		int height = max(y1, n - 1 - y1);
		ans = max(ans, base * height);
	}

	if (x1 != x2 and y1 != y2)
	{
		int height = abs(y2 - y1);
		int base = max({n - 1 - x1, x1, n - 1 - x2, x2});
		ans = max(ans, base * height);

		height = abs(x2 - x1);
		base = max({n - 1 - y1, y1, n - 1 - y2, y2});
		ans = max(ans, base * height);
	}

	return ans;

}

void solve(int t)
{

	int n;
	cin >> n;

	string s[n];

	for (int i = 0; i < n; i++) cin >> s[i];

	int a[n][n];

	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[i][j] - '0';
		}
	}


	int rowmin[10], rowmax[10], colmin[10], colmax[10];

	for (int x = 0; x < 10; x++)
	{
		rowmax[x] = -1;
		rowmin[x] = n;
		colmin[x] = n;
		colmax[x] = -1;

	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = a[i][j];
			rowmax[x] = max(rowmax[x], i);
			rowmin[x] = min(rowmin[x], i);
			colmin[x] = min(colmin[x], j);
			colmax[x] = max(colmax[x], j);
		}
	}


	int ans[10] = {0};
	vector< pair<int, int> > v[10];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[a[i][j]].pb({i, j});
		}
	}


	for (int k = 0; k < 10; k++)
	{
		//cout << rowmin[k] << " " << rowmax[k] << " " << colmin[k] << " " << colmax[k] << endl;
		for (auto x : v[k])
		{
			int i = x.F;
			int j = x.S;

			int a = max(j, n - 1 - j);
			int b = max(abs(i - rowmin[k]), abs(i - rowmax[k]));
			ans[k] = max(ans[k], a * b);
			b = max(abs(j - colmin[k]), abs(j - colmax[k]));
			a = max(i, n - 1 - i);
			ans[k] = max(ans[k], a * b);
		}
	}




	for (int i = 0; i < 10; i++)
	{
		cout << ans[i] << " ";
	}
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