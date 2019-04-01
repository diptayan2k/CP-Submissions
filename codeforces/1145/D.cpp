#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,b,a) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;


int main()
{
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll mi=32;
f(i,0,n-1) mi=min(mi,a[i]);
cout<<2+(mi^a[2]);

//0cout<<sum;

	return 0;
}
/*
5 4
6 3 2 11
5 9 4 2
3 3 3 3
4 8 2 2
7 8 6 4
6 3 2 11
5 9 3 8
3 4 3 2
4 2 3 2
7 8 6 4
*/
