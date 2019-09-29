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

bool diff(ll n)
{
    vector<ll> v;
    while(n!=0)
    {
        v.pb(n%10);
        n/=10;
    }
    //f(i,0,v.size()-1) cout<<v[i]<<" ";
    sort(v.begin(),v.end());

    if(v.size()==1) return true;
    f(i,0,v.size()-2) if(v[i]==v[i+1]) return false;
    return true;
}


int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l,r;
    cin>>l>>r;
    f(i,l,r) if(diff(i)) {cout<<i; exit(0);}
    cout<<-1;

}


