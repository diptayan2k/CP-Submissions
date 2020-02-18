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

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    string t;
    ll cn[26]={0};
    ll fr[n+1][26];
    ll pr[n+1][26];
    memset(fr,0,sizeof(fr));
    memset(pr,0,sizeof(pr));

    g(i,n-1,0)
    {
        cn[s[i]-'a']++;
        f(j,0,25)
        fr[i][j]=cn[j];
    }
    memset(cn,0,sizeof(cn));
    f(i,0,n-1)
    {
        cn[s[i]-'a']++;
        f(j,0,25)
        pr[i][j]=cn[j];
    }

    ll ans=1;

    map<pair<char,char>,ll> m;

    f(i,0,n-2)
    {
        f(j,0,25)
        {
            m[{s[i],((char)j+'a')}]+=fr[i+1][j];

            ans=max(ans,cn[j]);
        }
    }

    f(i,0,25)
    {
        f(j,0,25)
        {
            ans=max(ans,m[{((char)j+'a'),((char)i+'a')}]);
        }
    }

    cout<<ans<<endl;

}


