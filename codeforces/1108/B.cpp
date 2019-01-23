#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;

ll findlcm(ll arr[],ll n)
{

    ll ans = arr[0];


    for (ll i = 1; i < n; i++)
        ans = (((arr[i] * ans))/(__gcd(arr[i], ans)));

    return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll f[10005]={0};
f(i,0,n-1) f[a[i]]++;
sort(a,a+n);
ll b=a[n-1];
f(i,1,10004) if(b%i==0) f[i]--;
ll c;
g(i,10004,1) {if(f[i]>0) {c=i; break;}}
cout<<b<<" "<<c;
	return 0;
}
