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
#include <iostream>

using namespace std;






int main(){
string s;
cin>>s;
ll a=s.length();
ll d=0;
ll ff=1;
if(s[0]=='1')
{
    f(i,1,s.length()-1) if(s[i]=='1') ff=0;
}

if(ff) cout<<(s.length())/2;
else cout<<(s.length()+1)/2;



}
