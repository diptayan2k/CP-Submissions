#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{ long long int t,n,i;
 string s,o;
 cin>>t;
 while(t--)
 {
     cin>>n;
     cin>>s;
     o="YES";
     for(i=0;(n%2==0)?i<n/2:i<=n/2;i++)
     if(abs(s[i]-s[n-i-1])!=2&&s[i]!=s[n-i-1]) {o="NO"; break;}

     cout<<o<<endl;
 }

    return 0;
}