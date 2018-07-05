#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int count=2,i,j,n,d,a[100],k,l ;
cin>>n>>d;
for(i=0;i<n;i++) cin>>a[i];


sort(a,a+n);
for(i=0;i<n;i++)
{ k=a[i]+d; j=a[i]-d;
 if(a[i+1]-k>=d&&i<n-1) {count++; }
 if(i>0&&j-a[i-1]>=d&&j>l) {count++; }
l=k;
}



  cout<<count;


    return 0;
}
