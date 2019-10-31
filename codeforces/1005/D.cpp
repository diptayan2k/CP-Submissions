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
string s;
cin>>s;
ll n=s.size();
ll a[n+1];
a[0]=0;
f(i,0,n-1)
{
    a[i+1]=((s[i]-'0')+a[i])%3;
}
ll ans[n+1];
ans[0]=0;
f(i,1,n)
{
    ans[i]=ans[i-1];
    g(j,i-1,0)
    {
        if(a[i]==a[j]) {ans[i]=max(ans[j]+1,ans[i]);
        break;}
    }
}
//f(i,1,n) cout<<ans[i]<<" ";
//cout<<endl;
cout<<ans[n];

}
