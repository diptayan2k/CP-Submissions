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

ll n, k;
string s, p;
ll dp[201][201][201];

ll foo(ll idx, ll cnt, ll num)
{
	if (num > k) return NEGINF;
	if (idx == n) return 0;

	if (dp[idx][cnt][num] != -1) return dp[idx][cnt][num];
	ll res = NEGINF;

	res = max(res, foo(idx + 1, cnt + 1, num + (s[idx] != p[0])));
	res = max(res, cnt + foo(idx + 1, cnt + (p[1] == p[0]), num + (s[idx] != p[1])));
	res = max(res, foo(idx + 1, cnt + (s[idx] == p[0]), num));

	return dp[idx][cnt][num] = res;
}

void solve(int t)
{
	cin >> n >> k;
	cin >> s >> p;

	memset(dp, -1, sizeof(dp));
	cout << foo(0, 0, 0) << endl;





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