#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int n,s,a[200000],i,j,m=0;
cin>>n>>s;
for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
if(a[n/2]==s) {cout<<0; exit(0);}
if(a[n/2]<s)
{
 for(i=n/2;a[i]<=s&&i<n;i++) {m+=abs(a[i]-s); }
        cout<<m; exit(0);
}
if(a[n/2]>s)
{
 for(i=n/2;a[i]>=s&&i>=0;i--) {m+=abs(a[i]-s); }
        cout<<m; exit(0);
}




    return 0;
}