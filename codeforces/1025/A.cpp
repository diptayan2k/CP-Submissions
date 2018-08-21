#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int n,a[26]={0},i;
string s;
cin>>n;
cin>>s;
if(n==1) {cout<<"Yes"; exit(0);}
//sort(s.begin(),s.end());
for(i=0;i<n;i++)
 a[s[i]-97]++;
for(i=0;i<26;i++)
 {
     if(a[i]>=2) {cout<<"Yes";  exit(0);}
 }
cout<<"No";



    return 0;
}
