#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
using namespace std;
ll mod=1000000007;


void solve(ll t)
{
    ll n,k;
    cin>>n>>k;
    if(bits(n)>k)
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    multiset<ll,greater<ll> > s;
    map<ll,ll> m;
    g(i,60,0)
    {
        if((n&(1ll<<i))!=0)
        {
            //cout<<i<<endl;
            s.insert(i);
            m[i]++;
        }
    }

    //for(auto i:s) cout<<i<<" ";


    while(s.size()<k)
    {
        auto itr=s.begin();
        ll x=*itr;
        if(s.size()+m[x]<=k)
        {
            s.erase(itr);
            s.insert(x-1);
            s.insert(x-1);
            m[x]--;
            m[x-1]++;
            m[x-1]++;
        }
        else
        {
           auto ir=s.end();
           ir--;
           ll d=*ir;
           s.erase(ir);
           s.insert(d-1);
           s.insert(d-1);
           m[d]--;
           m[d-1]++;
           m[d-1]++;

        }

    }

    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;


}


int main()
{
    ll t=1;
    //scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}

