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
ll a,n,b,s;
ll q;
cin>>q;
while(q--)
{
    cin>>a>>b>>n>>s;
    ll p=s/n;
    if(p<a) s-=p*n;
    else s-=a*n;
    if(b>=s) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
}
