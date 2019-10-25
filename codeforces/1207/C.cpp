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
ll t;
cin>>t;
while(t--)
{
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll ab[n]={0};
    ll c=0;
    ll en=n-1;
    ll st=0;
    f(i,0,n-1)
    {
      if(s[i]=='1') { st=i; break; }

    }
    g(i,n-1,0)
    {
      if(s[i]=='1') { en=i; break; }

    }
    g(i,n-1,0)
    {
      if(s[i]=='1') {ab[i]=c; c=0; }
      else c++;
    }
    ll ans=0;
    if(st==0&&en==n-1)
    {
        cout<<n*a+n*b+b<<endl;
        continue;
    }
    //cout<<st<<" "<<en<<endl;
    ans=2*a+2*b;
    ans+=(st-1)*(a+b)+b;
    //cout<<ans<<endl;
    f(i,st,en-1)
    {
        if(s[i]=='1')
        {   ans+=a;
            if(ab[i]>=2)
            ans+=min((ab[i]-2)*a+4*a+(ab[i]-1)*b+4*b,(ab[i]+1)*2*b+ab[i]*a);
            else if(ab[i]==1) ans+=4*b+a;
            else ans+=2*b;
            i+=ab[i];
        //cout<<ans<<endl;
        }

    }
    //cout<<(ab[en]-1)*(a+b)+2*a+3*b<<endl;
    ans+=(ab[en]-1)*(a+b)+3*a+3*b;
    cout<<ans;
    //f(i,0,n-1) cout<<ab[i]<<" ";
    cout<<endl;
}
}
