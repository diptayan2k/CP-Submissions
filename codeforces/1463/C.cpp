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



void solve(int t)
{

	int n;
	cin >> n;

	int a[n + 1], x[n];

	for (int i = 0; i < n; i++) cin >> a[i] >> x[i];

	int pos = 0;
	int tt = 0;
	vector<int> v(n + 1, 0);
	int p[n];


	for (int i = 0; i < n; i++)
	{
		if (a[i] >= tt)
		{
			v[i] = 1;
			p[i] = pos;
			tt = a[i] + abs(x[i] - pos);
			//cout<<tt<<endl;
			pos = x[i];

		}

	}


	int cnt = 0;

	int last = -1;

	//op(t) << endl;
	a[n] = INF;
	v[n] = 1;
	//for (int i = 0; i < n; i++) cout << v[i] << " ";
	//cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == 1 and v[i + 1] == 1) cnt++;
		else if (i >= 1)
		{

			if (v[i] == 0 and (x[i] >= p[last] and x[i] <= x[last]) or (x[i] <= p[last] and x[i] >= x[last]))
			{
				int z = (a[last] + abs(x[i] - p[last]));
				if (z >= a[i] and z <= a[i + 1])
				{
					cnt++;
					//cout << i << " ";
				}
			}
		}
		if (v[i] == 1) last = i;
	}




	cout << cnt << endl;

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