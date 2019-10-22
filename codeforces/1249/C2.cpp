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
ll pp[51];
pp[0]=1;
f(i,1,50) pp[i]=pp[i-1]*3;
//f(i,0,40) cout<<pp[i]<<" ";
cin>>t;
while(t--)
{

ll n;
cin>>n;


if(n==1) cout<<1<<endl;
else if(n==2) cout<<3<<endl;
else{
vector<ll> v;

ll a=n;
ll ctr=0;
ll pos=-1;
while(n>0)
{
    if(n%3==2)
    ctr++;
    v.pb(n%3);
    if(v[v.size()-1]==0&&ctr)
    {
        v[v.size()-1]=1;
        ctr=0;
        pos=v.size()-1;
    }
  n/=3;
}
if(ctr>0)
{
			ll ans=pp[v.size()];
			cout<<ans<<endl;
}
else
{
    f(i,0,v.size()-1)
			if(v[i]==2)
			v[i]=0;
			ll ans=0;
			ctr=1;
			f(i,0,pos-1)
			v[i]=0;
			f(i,0,v.size()-1)
			{
				ans+=v[i]*ctr;
				ctr*=3;
			}
			cout<<ans<<endl;
}
}
}
}
