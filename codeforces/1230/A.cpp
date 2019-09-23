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
    ll a[4];
    f(i,0,3) cin>>a[i];
    ll s=0;
    f(i,0,3) s+=a[i];
    if(s%2!=0) {cout<<"NO"; exit(0);}
    s/=2;
    if(a[0]==s||a[1]==s||a[2]==s||a[3]==s) {cout<<"YES"; exit(0);}
    f(i,0,2)
    {
        f(j,i+1,3)
        if(a[i]+a[j]==s) {cout<<"YES"; exit(0);}
    }
     cout<<"NO";

}



















