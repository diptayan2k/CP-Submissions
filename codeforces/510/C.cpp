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
#define op1(x) cout<<"Case "<<x<<": "
using namespace std;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int N = 21;
ll n, m;
stack<ll> st;
bool vis[10001], rec[10001];
vector<ll> v[10001];
int flag = 0;

void dfs(ll u)
{
	vis[u] = true;
	rec[u] = true;
	//cout << u << " ";
	for (auto i : v[u])
	{
		if (rec[i]) flag = 1;
		if (vis[i]) continue;
		dfs(i);
	}
	st.push(u);
	rec[u] = false;
}



void solve(int t)
{
	cin >> n;
	memset(vis, false, sizeof(vis));
	memset(rec, false, sizeof(rec));
	string s[n];

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			string p = s[i];
			string q = s[j];
			ll fl = 0;
			for (int k = 0; k < min(p.length(), q.length()); k++)
			{
				if (p[k] != q[k])
				{
					fl = 1;
					v[p[k] - 'a'].pb(q[k] - 'a');
					break;
				}
			}
			if (fl == 0 and p.length() > q.length() )
			{
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		sort(v[i].begin(), v[i].end(), greater<ll>());
	}
	//cout << "HELLO" << endl;
	for (int i = 25; i >= 0; i--)
	{
		if (!vis[i]) dfs(i);
	}

	if (flag == 1)
	{
		cout << "Impossible" << endl;
		return;
	}

	while (!st.empty())
	{
		ll d = st.top();
		char ch = d + 'a';
		cout << ch;
		st.pop();
	}
	cout << endl;


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