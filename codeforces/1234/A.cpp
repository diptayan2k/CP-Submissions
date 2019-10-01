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





int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
ll q;
cin>>q;
while(q--)
{

    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n-1)
    cin>>a[i];
    ll s=0;
    f(i,0,n-1) s+=a[i];
    ll p=s/n;
    if(s%n!=0) p++;
    cout<<p<<endl;
}



}
