#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{ int n,i,a[100],b[100]={0},j;
cin>>n;
for(i=0;i<n;i++)
    cin>>a[i];
if(n==1) {cout<<1; exit(0);}
int max=-1;
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
 {if(a[i]==a[j]) b[i]++;}

if(b[i]>max) max=b[i];
}
cout<<max;

    return 0;
}
