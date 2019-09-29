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

bool diff(ll n)
{
    vector<ll> v;
    while(n!=0)
    {
        v.pb(n%10);
        n/=10;
    }
    //f(i,0,v.size()-1) cout<<v[i]<<" ";
    sort(v.begin(),v.end());

    if(v.size()==1) return true;
    f(i,0,v.size()-2) if(v[i]==v[i+1]) return false;
    return true;
}



int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll h,w;
    cin>>h>>w;
    ll r[h], c[w];
    f(i,0,h-1) cin>>r[i];
    f(i,0,w-1) cin>>c[i];
    ll a[h+1][w+1];
    memset(a,0,sizeof(a));
    f(i,1,h)
    {
        f(j,1,r[i-1])
        {a[i][j]=1;}
        if(r[i-1]<w) a[i][r[i-1]+1]=-1;
    }

    ll ff=0;
    f(i,1,w)
    {
        f(j,1,c[i-1])
        {if(a[j][i]==-1) ff=1;
         else a[j][i]=1;}
        if(c[i-1]<h)  {if(a[c[i-1]+1][i]==1) ff=1;  else a[c[i-1]+1][i]=-1;}

    }
    ll co=0;
    f(i,1,h)
    {
        f(j,1,w) if(a[i][j]==0) co++;

    }
    //cout<<ff<<" ";
    if(ff==1) { cout<<0; exit(0);}
    ll ans=1;
    f(i,1,co)
    ans=(ans%1000000007*2)%1000000007;
    cout<<ans;




}
