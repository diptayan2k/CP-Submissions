#include <iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
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
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

char a[26],A[26];
f(i,0,26-1) a[i]=i+97;
f(i,0,26-1) A[i]=i+65;

ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;

 string s;
 cin>>s;
 if(s.length()<=1)
    cout<<"NO"<<endl;
 else if(s.length()==2)
 {
     if(s[0]>=s[1])
        cout<<"NO"<<endl;
     else 
     { cout<<"YES"<<endl<<2<<endl;
         cout<<s[0]<<" "<<s[1]<<endl;}
 }
 else{
        cout<<"YES"<<endl;
 cout<<2<<endl;
 cout<<s[0]<<" "<<s.substr(1,n-1)<<endl;}
}

	return 0;
}
