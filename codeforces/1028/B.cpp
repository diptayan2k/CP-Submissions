#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum;


    for (sum = 0; n > 0; sum += n % 10, n /= 10);

    return sum;
}

int main()
{
   long long int n,m,i,a,b;
   //string s[1000];
   cin>>n>>m;
   for(i=0;i<2230;i++)
   cout<<5;
    cout<<endl;
    for(i=1;i<2230;i++)
    cout<<4;
    cout<<5;
    //while(sum+5<n) cout<<5;
    //cout<<5;
  /* for(i=1;i<=n;i++)
   { a=i;
    b=n-i;

    if(getSum(a+b)<=m){cout<<a<<b<<" "<<b<<a; exit(0);}*/



    return 0;
}
