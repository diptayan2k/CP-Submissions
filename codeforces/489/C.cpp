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
	ll m, n;
	cin >> n >> m;
	if(n==1 and m==0)
	{
		cout<<0<<" "<<0<<endl;
		return;
	}
	if (m == 0 or m > 9 * n)
	{
		cout << -1 << " " << -1 << endl;
		return;
	}

	string s1 = "";
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum + 9 <= m)
		{
			s1 += "9";
			sum += 9;
		}
		else
		{
			ll d = m - sum;
			s1 += (char)'0' + d;
			sum += d;
		}

	}


	string s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s2[0] == '0')
	{
		s2[0]++;
		for (int i = 1; i < n; i++)
		{
			if (s2[i] != '0')
			{
				s2[i]--;
				break;
			}
		}
	}
	cout << s2 << " " << s1 << endl;
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