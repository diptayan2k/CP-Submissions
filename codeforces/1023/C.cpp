#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ char s[200001];
 unsigned long long int n,k,i,j,l;
 cin>>n>>k>>s;
 if(n==k){ cout<<s; exit(0);};
j=k/2; l=k/2;
 for(i=0;i<n;i++)
 {
 if(s[i]=='('&&j)
 {cout<<s[i]; j--;}
if(s[i]==')'&&l)
 {cout<<s[i]; l--;}
if(!j&&!l) exit(0);}
 //for(i=0;i<n;i++) cout<<endl<<s[i]<<" "<<i;


    return 0;
}
