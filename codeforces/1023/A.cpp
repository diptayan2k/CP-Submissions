#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int m,n,i,j,k;
string s,t;
cin>>n>>m;
cin>>s>>t;
if(s==t) { cout<<"YES"; exit(0);}
//if(n==1) {cout<<"NO"; exit(0);}
for(i=0;s[i]!='\0';i++)
    if(s[i]=='*') break;
//cout<<i<<" ";
if(i==n&&s!=t) {cout<<"NO"; exit(0);}
if(n-1>m) {cout<<"NO"; exit(0);}
for(j=0;j<i;j++)
    if(s[j]!=t[j]) {cout<<"NO"; exit(0);}
//k=m-1;
for(j=n-1,k=m-1;j>i;j--,k--)
    if(s[j]!=t[k]) {cout<<"NO"; exit(0);}

    cout<<"YES";






      return 0;
}
