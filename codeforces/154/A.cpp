#include<bits/stdc++.h>
#define ll long long int
#define lld long double
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	ll n = s.length();
	s += "?";
	ll k;
	cin >> k;
	string p[k];
	for (int i = 0; i < k; i++)
	{
		cin >> p[i];
	}

	ll ans = 0;

	for (int i = 0; i < k; i++)
	{
		char ch1 = p[i][0];
		char ch2 = p[i][1];

		ll len = 0, one = 0, two = 0;
		for (int j = 0; j <= n; j++)
		{
			if (s[j] == ch1 or s[j] == ch2)
			{
				len++;
				if (s[j] == ch1) one++;
				else two++;
			}
			else
			{
				ans += min(one, two);
				len = 0;
				one = 0;
				two = 0;

			}

		}
	}

	cout << ans << endl;

}