#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define set set <ll, greater<ll> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;



int main()
{



ll t;
cin>>t;
while(t--)
{
    string s;
    cin>>s;


    if(s.length()>=5)
    f(i,2,s.length()-3)
    {
        if(s.substr(i-2,5)=="twone")
            s[i]='.';
    }
    if(s.length()>=3)
    f(i,1,s.length()-2)
    {
        if(s.substr(i-1,3)=="two")
            s[i]='.';
    }
    if(s.length()>=3)
    f(i,1,s.length()-2)
    {
        if(s.substr(i-1,3)=="one")
            s[i]='.';
    }


    ll c=0;
    f(i,0,s.length()-1)
    {
        if(s[i]=='.') c++;
    }
    cout<<c<<endl;
    f(i,0,s.length()-1)
    {
        if(s[i]=='.') cout<<i+1<<" ";
    }

    cout<<endl;


}



}







