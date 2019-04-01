#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,b,a) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;

bool sorted(ll u,ll l,ll a[])
{
    f(i,u,l-1)
    if(a[i+1]<a[i]) return false;
    return true;
}

int main()
{
ll n;
cin>>n;
ll a[n];
f(i,0,n-1) cin>>a[i];
ll s=1;
ll si=1;
//if(sorted(0,n-1,a)) cout<<"YAY";

while(s<=n)
{ for(ll i=0;i+s<=n;i+=s)
  {
      if(sorted(i,i+s-1,a)) si=max(si,s) ;

  }
  //cout<<s<<endl;
  s*=2;

}
cout<<si;

	return 0;
}
