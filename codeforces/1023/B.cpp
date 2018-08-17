#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ unsigned long long int n,k,l;
cin>>n>>k;
if(k==1) {cout<<0; exit(0);}
if(k<=n&&k%2!=0)
{cout<<1+((k-2)/2); exit(0);}
if(k<=n&&k%2==0)
{cout<<((k-2)/2); exit(0);}
if(k>=2*n) {cout<<0; exit(0);}
//if(k<3) {cout<<0; exit(0);}
l=k-n;
if(k%2==0&&k/2>l&&k/2<n) cout<<(n-l)/2;
else cout<<(n-l)/2+1;
//if((2*n-k)%2==0) cout<<((2*n-k)/2);
//else cout<<((2*n-k)/2)+1;
//(k%2==0)?cout<<((2*n-k)/2):cout<<((2*n-k)/2)+1;
    return 0;
}
