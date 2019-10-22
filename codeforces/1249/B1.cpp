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

ll siz[200001];
ll a[200001];


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

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
while(t--)
{

ll n;
cin>>n;
intialise(n);
ll a[n];
f(i,0,n-1) {cin>>a[i]; if(!check_connection(i+1,a[i])) union_(i+1,a[i]); }


f(i,1,n) cout<<siz[root(i)]<<" ";
cout<<endl;
}


}







