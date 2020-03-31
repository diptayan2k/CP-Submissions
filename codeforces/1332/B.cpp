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
#define bits(x) __builtin_popcount(x)
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll mod=1e9+7;
ll pr[11]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve(ll t)
{
    ll n;
    cin>>n;
    ll a[n];

    f(i,0,n-1) cin>>a[i];
    ll c[n]={0};
    map<ll,ll> m;
    f(i,0,10)
    {
        f(j,0,n-1)
        {
            if(a[j]%pr[i]==0 and c[j]==0)
            {
                c[j]=i+1;
                m[i+1]++;
            }

        }

    }
    cout<<m.size()<<endl;
    ll k=1;
    map<ll,ll> pp;
    for(auto i:m) pp[i.F]=k++;

    f(i,0,n-1) cout<<pp[c[i]]<<" ";
    cout<<endl;



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    cin>>t;

    f(i,1,t)
    {
        solve(i);
    }

}

