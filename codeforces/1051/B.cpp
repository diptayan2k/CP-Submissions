#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define ss string
#define cc char
#define vv vector
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f1(j,c,d) for(ll j=c;j>=d;j--)
using namespace std;

int main()
{
    ll l,r;
    cin>>l>>r;
    if(r-l+1<2) {cout<<"NO"; exit(0);}
    cout<<"YES"<<endl;
    for(ll i=l;i<=r;i+=2)
    cout<<i<<" "<<i+1<<endl;






    return 0;
}
