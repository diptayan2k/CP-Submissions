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

ll siz[1000001];
ll a[1000001];


void intialise(ll n)
{
    f(i,0,n)
    {
        a[i]=i;
        siz[i]=1;
    }

}

ll root(ll i)
{
    ll j=i;
    while(a[i]!=i)
    {
        i=a[i];
        a[j]=i;
        j=i;
    }
    return i;
}

void union_(ll x, ll y)
{
   ll rootx=root(x);
   ll rooty=root(y);
    if(siz[rooty]>siz[rootx]) swap(x,y);
    a[rooty]=rootx;
    siz[rootx]+=siz[rooty];

}

bool check_connection(ll x, ll y)
{
   ll rootx=root(x);
   ll rooty=root(y);

    if(rootx==rooty) return true;
    else return false;

}


int main()
{

ll n;
cin>>n;
string s[n];
vector<ll> vl[26];
f(i,0,n-1)
{
    cin>>s[i];
    f(j,0,s[i].length()-1)
    {
        vl[s[i][j]-'a'].pb(i+1);
    }
}

intialise(n);

f(i,0,25)
{
    if(vl[i].size()>1)
    {
        f(j,1,vl[i].size()-1)
        {
            if(!check_connection(vl[i][0],vl[i][j]))
            union_(vl[i][0],vl[i][j]);

        }
    }
}

map<ll,ll> m;

f(i,1,n)
m[root(i)]++;
cout<<m.size();


return 0;
}









