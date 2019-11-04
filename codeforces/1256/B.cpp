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

ll q;
cin>>q;
while(q--)
{
ll n;
cin>>n;
ll a[n];
map<ll,ll> m;

ll b[n];
f(i,0,n-1)
{
    cin>>a[i];
    b[i]=a[i];
}
ll flag=0;
while(flag==0)
{

flag=1;
g(i,n-2,0)
{
    if(a[i]>a[i+1]&&m[i]==0) {swap(a[i],a[i+1]); m[i]=1; flag=0; }
}


}

f(i,0,n-1) cout<<a[i]<<" ";
cout<<endl;
}
}
