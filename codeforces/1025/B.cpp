#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include<vector>
//vector < <long long int,long long int> > v;
int main()
{ long long int n,a[150000],b[150000],i,l=0,c,j,k,t;
cin>>t;
for(i=0;i<t;i++){
cin>>c>>n;
a[i]=c; b[i]=n;
l=__gcd(l,c*n);
}
for(i=0;i<t;i++)
{
    if(__gcd(l,a[i])>1)
        l=__gcd(l,a[i]);
        else l=__gcd(l,b[i]);
}
if(l==1) cout<<-1;
else cout<<l;

    return 0;
}
