#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(a,n) for(ll i=a;i<n;i++)
int main()
{ ll n,k,s1=0,s2=0;
vector <ll> v;
string s;
   cin>>n;
   f(1,n+1)
   { if(i%2==1) s1+=i;
     if(i%2==0) s2+=i;
   }
  //cout<<s1<<" "<<s2;
   if(__gcd(s1,s2)>1) {cout<<"Yes"<<endl;
    (n%2==0)?cout<<n/2<<" ":cout<<n/2+1<<" ";
    for(ll i=1;i<=n;i+=2) cout<<i<<" ";
    cout<<endl;
    cout<<n/2<<" ";
    for(ll i=2;i<=n;i+=2) cout<<i<<" ";
   exit(0); }
 cout<<"No";

    return 0;
}
