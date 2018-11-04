#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define ff long double
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define w while
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;

binary(ll c[],ll m,ll v)
{
    ll hi=m-1;
    ll lo=0;
    ll mid;
    while(hi>=lo)
    {
        mid=(hi+lo)/2;
        if(c[mid]>v) hi=mid-1;
        else if(mid<m-1 &&c[mid]<=v &&c[mid+1]>v) return mid;
        else lo=mid+1;
    }
    return mid;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   ll n,m;
   cin>>n>>m;
   ll a[m+n];
   ll b[m+n];
   ll c[m];
   f(i,0,m+n-1) cin>>a[i];
   ll j=0;
   ll k=0;
   ll r[n];
   f(i,0,n+m-1) {cin>>b[i]; if(b[i]==1) c[j++]=a[i]; else r[k++]=a[i];}
   ll d[m]={0};
    k=0;
//   ll j=0;
   if(m==1)
   {
       cout<<m+n-1; exit(0);
   }
   f(i,0,n-1)
   {
       ll j=binary(c,m,r[i]);
       //cout<<j<<" ";
       if(j<m-1)
       {
           if(abs(c[j]-r[i])<=abs(c[j+1]-r[i])) d[j]++;
           else d[j+1]++;
       }
       else d[j]++;
   }

   f(i,0,m-1) cout<<d[i]<<" ";


	return 0;
}

