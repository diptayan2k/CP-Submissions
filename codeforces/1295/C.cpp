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

void solve()
{


}





int main()
{
ll k;
cin>>k;

while(k--)
{
    string s,t;
    cin>>s>>t;
    ll n=s.length();
    ll a[26][n+1];
    vector<ll> v[26];
    f(i,0,s.length()-1)
    v[s[i]-'a'].pb(i);

    /*
    f(i,0,25)
    {
        cout<<(char)(i+'a')<<"-";
        for(ll j: v[i]) cout<<j<<" ";
        cout<<endl;
    }*/

    vector<ll> ::iterator itr;
    ll c=1;
    ll pos=-1;
    f(i,0,t.length()-1)
    {
        ll j = t[i]-'a';

        itr=upper_bound(v[j].begin(),v[j].end(),pos);
        if(pos==-1&&itr==v[j].end())
        {
            c=-1;
            break;
        }

        else if(itr==v[j].end())
        {
            pos=-1;
            c++;
            i--;
        }

        else
        {pos=v[j][itr-v[j].begin()];
         //cout<<pos<<endl;
        }

    }
    cout<<c<<endl;

}

}
