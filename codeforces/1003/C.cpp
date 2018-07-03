#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{ float a[5000],b[5001],max=0,c,m;
int  n,i,k;
cin>>n>>k;
cin>>a[0];
b[0]=0;
b[1]=a[0];
for(i=1;i<n;i++)
{cin>>a[i];
 b[i+1]=a[i]+b[i];}
while(k<=n)
{for(i=1;i+k-1<=n;i++)
{ c=(b[i+k-1]-b[i-1])/k;

if(c>max){ max=c;}}
k++;}


cout<<fixed<<setprecision(15)<<max;


    return 0;
}
