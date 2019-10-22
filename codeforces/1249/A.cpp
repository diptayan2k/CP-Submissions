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
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
while(t--)
{
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll ans=0;
ll c=0;
f(i,0,n-1)
{  c=0;
    f(j,0,n-1)
    {
        if(abs(a[i]-a[j])==1) c++;
    }
 ans=max(ans,c);

}
if(ans==0) cout<<1<<endl;
else cout<<2<<endl;
}


}







