#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int n,i,j,m=0;
  string a,b;
  cin>>n;
 cin>>a>>b;
 for(i=0;i<n;i++)
 {
     //if(i<n-1&&a[i+1]==b[i]&&a[i]!=b[i]) m+=1;
    if(a[i]!=b[i])
    {  if((i<n-1)&&(a[i+1]==b[i])&&(a[i]==b[i+1]))
       {
           m+=1;
           swap(a[i],a[i+1]);
       }
       else m+=1;

    }
 }
cout<<m;
    return 0;
}
