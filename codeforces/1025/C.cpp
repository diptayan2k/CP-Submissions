#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int n,a[26]={0},i,l=0,c,j,k;
string s;
cin>>s;
s+=s;
n=s.length();c=0;
for(i=1;i<s.length();i++)
{
    if(s[i]==s[i-1]) l=i;
    c=max(i-l+1,c);

}
    cout<<min(c,n/2);    //bwwwbwwbw





    return 0;
}
