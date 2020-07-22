#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
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
	ll t;
	cin >> t;
	while (t--)
	{
		vector<int> v;
		ll n;
		string a, b;

		cin >> n >> a >> b;

		char first[n];
		ll p = 0;
		ll q = n - 1;
		ll k = 0;


		while (p <= q )
		{
			if (k % 2 == 0)
				first[k++] = a[p++];
			else
				first[k++] = a[q--];
			//cout << p << " " << q << endl;
		}

		for (int i = 1; i < n; i += 2)
		{
			if (first[i] == '0') first[i] = '1';
			else first[i] = '0';
		}


		/*
		for (int i = 0; i < n; i++)
		{
			cout << first[i] << " ";
		}
		cout << endl;*/




		for (int i = n - 1; i >= 0; i--)
		{

			if (first[n - 1 - i] == b[i])
			{
				v.pb(1);
				v.pb(i + 1);
			}
			else
			{
				v.pb(i + 1);
			}

		}


		cout << v.size() << " ";
		for (auto i : v) cout << i << " ";
		cout << endl;
	}

}