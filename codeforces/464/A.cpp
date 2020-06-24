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
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = 1e18;
const int N = 20;

ll longest_suffix(string s)
{
	string d = s;
	reverse(d.begin(), d.end());
	s = d + "#" + s;

	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}

	return pi[n - 1];
}

void solve(int t)
{
	string d[6];

	for (int i = 0; i < 400; i++) d[0] += "abc";
	for (int i = 0; i < 400; i++) d[1] += "bac";
	for (int i = 0; i < 400; i++) d[2] += "cab";
	for (int i = 0; i < 400; i++) d[3] += "acb";
	for (int i = 0; i < 400; i++) d[4] += "bca";
	for (int i = 0; i < 400; i++) d[5] += "cba";
	sort(d, d + 6);
	string s;
	ll n, p;
	cin >> n >> p;
	cin >> s;

	for (int i = n - 1; i >= 0; i--)
	{

		for (int j = s[i] - 'a' + 1; j < p; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				string pp = s.substr(0, i) + (char)(j + 'a') + d[k].substr(0, n - (i + 1));
				//cout << pp << endl;
				//reverse(pp.begin(), pp.end());
				if (n - (i + 1) > 2 and p < 3)
				{
					cout << "NO" << endl;
					return;
				}

				if (i + 2 <= n and longest_suffix(pp.substr(0, i + 2)) > 1) continue;
				if (i + 3 <= n and longest_suffix(pp.substr(0, i + 3)) > 1) continue;
				if (i + 4 <= n and longest_suffix(pp.substr(0, i + 4)) > 1) continue;
				//if (pp == "cbd") cout << longest_suffix(pp) << " " << longest_suffix(pp.substr(0, i + 1)) << endl;


				if (longest_suffix(pp) <= 1 and longest_suffix(pp.substr(0, i + 1)) <= 1)
				{
					//reverse(pp.begin(), pp.end());
					cout << pp << endl;
					return;
				}



			}
		}
	}
	cout << "NO" << endl;

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