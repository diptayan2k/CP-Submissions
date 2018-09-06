#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(a,n) for(ll i=a;i<n;i++)
int main()
{
ll n,k,s1=0,s2=0,sc1=0,sc2=0,l,m;
vector <ll> v;
string s;
   cin>>n;
   ll a[n],b[n];
   f(0,n)
   { cin>>a[i];
   s1+=a[i];
   }
   f(0,n)
   { cin>>b[i];
   s2+=b[i];
   }
   if(n==1)
   {
       if(s1>s2)
        cout<<s1-s2;
       else cout<<0;
       exit(0);
   }



   sort(a,a+n);
   sort(b,b+n);
   l=n-1;
   m=n-1;
   ll i=0;
   while(l>=0&&m>=0)
   {
     if(i%2==0)
     {
         if(a[l]<b[m])
         {//s2-=b[m];
          m--;}
        else if(a[l]>=b[m])
         {sc1+=a[l];
          l--;}


    }

     if(i%2==1)
     {
         if(b[m]<a[l])
         {//s1-=a[l];
          l--; }
       else if(b[m]>=a[l])
         {sc2+=b[m];
          m--;}

     }
     i++;
     //cout<<sc1<<" "<<sc2<<endl;
    }
   // cout<<l<<" "<<m<<" "<<i<<" ";
    ll j;
    if(m>=0)
    {
        for((i%2==0)?j=m-1:j=m;j>=0;j-=2) sc2+=b[j];
    }
   if(l>=0)
    {
        for((i%2==1)?j=l-1:j=l;j>=0;j-=2) sc1+=a[j];
    }

   cout<<sc1-sc2;


    return 0;
}
