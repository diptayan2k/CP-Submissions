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
const ll INF = 1e18;
const int N = 20;
map<ll, ll> m;




void solve(int t)
{

	string s;
	cin >> s;

	vector<pair<ll, ll> > v;
	stack<pair<char, ll> > st;
	ll ma = 0; \
	ll n = s.length();
	ll b[n];
	ll cn = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '[' or s[i] == ']') cn++;
		b[i] = cn;
	}
	ll x = 0;
	ll y = -1;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' or s[i] == '[')
		{
			st.push({s[i], i});
		}
		else if (!st.empty())
		{
			if (s[i] == ')' and st.top().F == '(')
			{
				st.pop();
				ll p;
				if (st.empty()) p = 0;
				else p = st.top().S + 1;
				ll q = i;

				ll num;
				if (p == 0)
				{
					num = b[q];
				}
				else num = b[q] - b[p - 1];

				if (num / 2 > ma)
				{
					ma = num / 2;
					x = p;
					y = q;
				}
			}
			else if (s[i] == ']' and st.top().F == '[')
			{
				st.pop();
				ll p;
				if (st.empty()) p = 0;
				else p = st.top().S + 1;
				ll q = i;

				ll num;
				if (p == 0)
				{
					num = b[q];
				}
				else num = b[q] - b[p - 1];

				if (num / 2 > ma)
				{
					ma = num / 2;
					x = p;
					y = q;
				}
			}

			else
			{
				st.push({s[i], i});
			}


		}
		else
		{
			st.push({s[i], i});
		}

	}

	cout << ma << endl;
	cout << s.substr(x, y - x + 1);






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