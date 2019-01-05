#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define ff long double
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;


int main(){
ll n;
cin>>n;
ll sum=0,a=1;
f(i,1,n)
{
    sum+=i;
    a++;
    if(sum>=n) break;
    sum+=i;
    a++;
    if(sum>=n) break;
}
cout<<a;


	return 0;
}



// Function to return gcd of a and b

