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
ll w,h,u1,d1,u2,d2;
cin>>w>>h>>u1>>d1>>u2>>d2;

g(i,h,1)
{
w+=i;
if(i==d2) w-=u2;
else if(i==d1) w-=u1;
w=max(w,(ll)0);

}
cout<<w;



	return 0;
}



// Function to return gcd of a and b

