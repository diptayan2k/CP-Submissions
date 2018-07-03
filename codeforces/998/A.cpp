#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{ int a[1000],b[1000],o,i,f=0,n;
cin>>n;
cin>>a[0];
b[0]=a[0];
for(i=1;i<n;i++)
{cin>>a[i]; b[i]=a[i]+b[i-1];}
if(n==1) { cout<<-1<<endl; exit(0);}
else
{ for(i=0;i<n-1;i++)
  if(b[i]!=b[n-1]-b[i])
   {
       f=1;
       break;
   }

}

if(f==1)
{  i++;
    cout<<i<<endl;

    while(i--)
    cout<<i+1<<" ";}
else cout<<-1;

    return 0;
}
