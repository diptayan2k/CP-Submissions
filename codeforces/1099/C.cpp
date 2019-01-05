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
ll k;
string s;
cin>>s>>k;
ll c=0,d=0;
f(i,0,s.length()-1)
{
    if(s[i]=='?') c++;
    if(s[i]=='*') d++;
}
if(k==s.length()-(c+d))
{
    f(i,0,s.length()-1)
    {
       if(s[i]!='?'&&s[i]!='*') cout<<s[i];
    }
     exit(0);
}
if(k<s.length()-2*(c+d))
{
    cout<<"Impossible"; exit(0);
}
if((k>s.length()-(c+d))&&d==0)
{
    cout<<"Impossible"; exit(0);
}
ll f=0;
if(k>s.length()-(c+d))
{
    f(i,0,s.length()-1)
   { if(s[i]=='*'&&f==0)
     {
         f(j,1,k-(s.length()-(c+d)))
         cout<<s[i-1];
         f=1;
     }
     else if(s[i]!='?'&&s[i]!='*') cout<<s[i];
   }
}

if(k<s.length()-(c+d))
{ ll p=0;
    f(i,0,s.length()-2)
   { if((s[i+1]=='*'||s[i+1]=='?')&&p<s.length()-(c+d)-k)
     { s[i]='?';
       p++;
      }}

    f(i,0,s.length()-1)
    {
       if(s[i]!='?'&&s[i]!='*') cout<<s[i];
    }



}
//cout<<c<<" "<<d<<" "<<s.length();

	return 0;
}



// Function to return gcd of a and b

