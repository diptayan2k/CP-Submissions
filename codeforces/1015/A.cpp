#include <iostream>
#include<bitset>
using namespace std;

int main()
{ int m,n,l,r,i,c;
cin>>n>>m;
bitset<100> bokachoda;
while(n--)
{
    cin>>l>>r;
    for(i=l-1;i<r;i++)
        bokachoda[i]=1;
}
c=m-bokachoda.count();
cout<<c<<endl;
for(i=0;i<m;i++)
    if(bokachoda[i]==0) cout<<i+1<<" ";







    return 0;
}
