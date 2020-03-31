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






void solve(ll t)
{
    ll n,k;
    ll p;
    cin>>n>>k;
    p=n/k;
    string s;
    vector<string> ss;
    cin>>s;
    for(ll i=0;i<n;i+=k)
    {
        ss.pb(s.substr(i,k));
    }

    ll ans=0;
    f(i,0,k/2-1)
    {
        ll an=1000000000;
        f(l,0,25)
        {
            ll cn=0;
            f(j,0,ss.size()-1)
            {
                if((ss[j][i]-'a')!=l) cn++;
                if((ss[j][k-1-i]-'a')!=l) cn++;
            }
            an=min(an,cn);
        }
        ans+=an;


    }
    ll add=10000000007;
    if(k%2==1)
    {
        ll d=k/2;
        f(j,0,25)
        {
            ll cn=0;
            f(i,0,ss.size()-1)
            {
                if((ss[i][d]-'a')!=j) cn++;
            }
            add=min(add,cn);

        }
        ans+=add;

    }
    cout<<ans<<endl;








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

