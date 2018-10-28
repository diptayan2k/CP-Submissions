#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define ff long double
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define w while
#define F first
#define vv vector
#define S second
#define mp make_pair
using namespace std;

ll m=1000000000+7;

int main()
{ ll n;
cin>>n;
ll a[n],s=0;
f(i,0,n-1) {cin>>a[i]; s+=a[i];}
m=-1;
f(i,0,n-1) m=max(m,a[i]);
ll k=m;

ll sum=0;
f(i,0,n-1) sum+=k-a[i];
ll s1=sum;
do
{   ll sum=0;
    f(i,0,n-1)
    sum+=k-a[i];

    s1=sum;
    //cout<<k<<" "<<s1<<" "<<s<<endl;
   if(s1<=s) k++;
}while(s1<=s);
cout<<k;

    return 0;
}
