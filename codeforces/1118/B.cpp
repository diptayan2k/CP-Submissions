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
   ll n;
   cin>>n;
   ll a[n],s=0;
   f(i,0,n-1) cin>>a[i];
   ll od[n+1]={0};
   ll ev[n+1]={0};
   od[0]=0;
   ev[0]=0;
   for(ll i=0;i<n;i+=2)
   { s+=a[i];
    od[i+1]=s;
   }
   s=0;
   for(ll i=1;i<n;i+=2)
   { s+=a[i];
       ev[i+1]=s;
   }
   f(i,1,n)
   {
       if(od[i]==0)
        od[i]=od[i-1];
       if(ev[i]==0)
        ev[i]=ev[i-1];

   }
   ll count=0;
   f(i,0,n-1)
   {

          if(od[i]+ev[n]-ev[i+1]==ev[i]+od[n]-od[i+1]) count++;


   }

   /*f(i,0,n) cout<<od[i]<<" ";
   cout<<endl;
   f(i,0,n) cout<<ev[i]<<" ";
   cout<<endl;*/
   cout<<count;

	return 0;
}
