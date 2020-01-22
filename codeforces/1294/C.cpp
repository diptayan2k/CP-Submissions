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
//#define set set <ll, greater<ll> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void solve()
{
    ll n;
    ll m;
    cin>>n;
   m=n;
   vector<ll> v;
    while (n % 2 == 0)
    {



        v.pb(2);
        //cout<<2<<" ";
        n = n/2;
    }


    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            v.pb(i);

            n = n/i;
        }
    }


    if (n > 2)
        v.pb(n);

    sort(v.begin(),v.end());
    if(v.size()<3)
    {
        cout<<"NO";
        return;
    }
    ll p=v[0];
    if(p<2)
    {
        cout<<"NO";
        return;
    }
    ll q=1;
    f(i,1,v.size()-1)
    {
         q*=v[i];
         if(q!=p) break;

    }

    if(q==p||q<2)
    {
        cout<<"NO";
        return;
    }


    ll r=m/(p*q);

    if(p==r||q==r||r<2)
        {
        cout<<"NO";
        return;
    }

    cout<<"YES"<<endl;
    cout<<p<<" "<<q<<" "<<r;




}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll t;
cin>>t;
while(t--)
{
    solve();
    cout<<endl;
}


}
