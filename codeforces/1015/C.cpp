#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int m,n,l,r,i,c[100000],a[100000],b[100000],d[100000],sum=0,suma=0,sumb=0,j;
cin>>n>>m;
sumb=0;
suma=0;
for(i=0;i<n;i++)
{
cin>>a[i]>>b[i];
c[i]=a[i]-b[i];
sumb=sumb+b[i];
suma=suma+a[i];
}
sort(c,c+n);
//sum=0;


if(sumb>m) {cout<<-1; exit(0);}
if(sumb==m) {cout<<n; exit(0);}
//if(suma<=m) {cout<<0<<endl; exit(0);}
//l=suma-m;
i=n-1;r=0;
while(suma>m&&i>=0)
{ suma-=c[i--];
    
   r++;
}
cout<<r;






    return 0;
}
