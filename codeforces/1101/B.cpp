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
string s;
cin>>s;
ll a=-1, b=-1,c=0,d=0;
f(i,0,s.length()-1)
{
    if(s[i]=='[') {a=i; break;}
}
f(i,a,s.length()-1)
{
    if(s[i]==']') {b=i;}
}
if(a==-1||b==-1||a>b) {cout<<-1; exit(0);}
else
{ ll p,q;
    f(i,a,b)
   {if(s[i]==':') c++;
   if(s[i]==':') q=i;}

   f(i,a,b)
   if(s[i]==':') {p=i; break;}

   f(i,p,q)
   if(s[i]=='|') d++;

}
if(c<2) {cout<<-1; exit(0);}
else
{
    cout<<(4+d);
}


	return 0;
}



// Function to return gcd of a and b

