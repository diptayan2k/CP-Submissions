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

ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);


ll mergeSort(ll arr[], ll array_size)
{
	ll temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
ll _mergeSort(ll arr[], ll temp[], ll left, ll right)
{
	ll mid, inv_count = 0;
	if (right > left) {

		mid = (right + left) / 2;

		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
ll merge(ll arr[], ll temp[], ll left,
         ll mid, ll right)
{
	ll i, j, k;
	ll inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
	(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

void solve(int t)
{
	ll n;
	cin >> n;

	string s1, s2;
	cin >> s2;
	s1 = s2;
	reverse(s2.begin(), s2.end());

	vector<ll> Q[26];
	for (int i = 0; i < n; ++i )
		Q[s2[i] - 'a'].push_back(i);

	ll p[n + 1];
	ll temp[26] = {0};
	for (int i = 0; i < n; ++i )
		p[i] = 1 + Q[ s1[i] - 'a'][ temp[s1[i] - 'a']++];

	/*
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";

	}*/

	ll ans = mergeSort(p, n);

	cout << ans << endl;




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