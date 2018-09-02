#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{ long long int n,m=0;
cin>>n;
while(n!=0)
{  n/=2;
    m++;
}
cout<<m;
    return 0;
}
