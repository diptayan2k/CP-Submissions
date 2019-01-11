#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;




int main(){
ll q;
cin>>q;
while(q--)
{
    ll l,r,a;
    ll x,ff=0;
    cin>>l>>r>>a;
    if(l<=a)
    {
        x=r/a+1;
    }
    else x=1;



    cout<<a*x<<endl;
}
	return 0;
}



// Function to return gcd of a and b

