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

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    f(i,0,n-1)
    {
        f(j,i+1,n-1)
        {
            ll p = s[i]-'0';
            ll q= s[j]-'0';
            if((p*10+q)%2==1 && (p+q)%2==0)
            {
                cout<<p<<q<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
    return;
}

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       solve();
   }

}