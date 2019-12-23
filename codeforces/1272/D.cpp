#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define set set <ll, greater<ll> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;




int main()
{
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll pre[n]={0};
ll pos[n]={0};
pre[0]=1;
pos[n-1]=1;
ll l=0;
f(i,1,n-1)
{
    if(a[i]>a[i-1]) pre[i]= pre[i-1]+1;
    else pre[i]=1;


}
l =1;
g(i,n-2,0)
{
    if(a[i]<a[i+1]) pos[i]=pos[i+1]+1;
    else pos[i]=1;

}
ll ans=0;
l=1;
f(i,1,n-1)
{
    if(a[i]>a[i-1]) l++;
    else l=1;
    ans=max(ans,l);
}


f(i,1,n-2)
{
    if(a[i-1]<a[i+1])
    ans=max(pre[i-1]+pos[i+1],ans);
}

cout<<ans<<endl;


return 0;
}







