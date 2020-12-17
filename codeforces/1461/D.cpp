#include <iostream>
#include<bits/stdc++.h>
#define ll int
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
const int mod = 1000000007;
//const int mod = 998244353;
const int INF = 1000000000000000000;//LLONG_MAX;
const int NEGINF = LLONG_MIN;
const int N = 18;
const int MAXN = 1000001;

int n;
int a[100001];
int b[100001];

map<int, int> mp;

void foo(int l, int r)
{
	//cout << l << " " << r << endl;
	if (l > r) return;
	if (l == r) {mp[a[l]]++; return;}

	mp[b[r] - b[l - 1]]++;

	int mid = (a[l] + a[r]) / 2;
	int idx = upper_bound(a + 1, a + n + 1, mid) - a;

	//cout << l << " " << r << " " << idx << endl;
	if (idx == l or idx - 1 == r) return;

	foo(l, idx - 1);
	foo(idx, r);
}

void solve(int t)
{
	int q;
	cin >> n >> q;

	mp.clear();


	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	b[0] = 0;
	for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];

	foo(1, n);

	//for (auto i : mp) cout << i.F << " " << i.S << endl;

	while (q--)
	{
		int x;
		cin >> x;
		if (mp[x] > 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}


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