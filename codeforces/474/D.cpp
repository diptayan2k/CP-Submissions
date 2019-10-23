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
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;
ll mod=1000000007;



int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t,k;
cin>>t>>k;
ll a[100001];
a[0]=0;
f(i,1,k-1) a[i]=1;
a[k]=2;
f(i,k+1,100000) a[i]=(a[i-1]%mod+a[i-k]%mod)%mod;
ll b[100001];
b[0]=a[0];
f(i,1,100001) b[i]=(b[i-1]%mod+a[i]%mod)%mod;
while(t--)
{
    ll aa,bb;
    cin>>aa>>bb;

    cout<<(b[bb]-b[aa-1]+mod)%mod<<endl;

}
}
