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
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;




int main()
{
ll n,k;
cin>>n>>k;
string s;
cin>>s;
if(k==0) {cout<<s; exit(0);}
if(s.length()==1) {cout<<0; exit(0);}
if(s[0]>'1') {s[0]='1'; k--;}
if(k==0) {cout<<s; exit(0);}
f(i,1,n-1){
if(s[i]!='0') {s[i]='0'; k--;}
if(k<=0) break;
}
cout<<s;

}



















