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


    for(string i:{"twone","one","two"})
        {

            for(ll j=0; j<=(ll)s.length()-(ll)i.length(); j++)
            {
                //cout<<i<<" "<<(ll)s.length()-(ll)i.length()<<" "<<j<<endl;
                if(s.substr(j,i.length())== i)
                {
                    s[j+i.length()/2]='.';
                }
            }

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







