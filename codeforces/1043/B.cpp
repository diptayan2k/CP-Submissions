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
ll a[n];
f(i,0,n-1) {cin>>a[i];}
ll b[n];
b[0]=a[0];
f(i,1,n-1) b[i]=a[i]-a[i-1];
vector <ll> c[n];
vv <ll> v;
f(i,0,n-1)
{   //ll k=0;
    f(j,i,n-1)
     {
         c[i].push_back(b[j]);
     }
}

/*f(i,0,n-1)
{
    f(j,0,c[i].size()-1) cout<<c[i][j]<<" ";
    cout<<endl;
}*/


ll count=0;
f(i,1,n-1)
{ ll flag=1;
    f(j,0,c[i].size()-1)
    {
        if(c[i][j]!=b[j]) flag=0;
    }
    if(flag==1) {count++; v.push_back(n-c[i].size());}
}
v.push_back(n);
cout<<count+1<<endl;
sort(v.begin(),v.end());
f(i,0,v.size()-1) cout<<v[i]<<" ";

    return 0;
}
