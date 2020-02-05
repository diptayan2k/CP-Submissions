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
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll ar[n];
    f(i,0,n-1) cin>>ar[i];
    ll br[n];
    f(i,0,n-1)
    {
        ll p=ar[i]%(a+b);
        if(p==0) p=a+b;
        if(p<=a) br[i]=0;
        if(p>a)
        {
            br[i]=p/a;
            if(p%a==0) br[i]--;
        }

        //cout<<br[i]<<" ";
    }
    sort(br,br+n);
    ll s=0;
    ll ans=0;
    f(i,0,n-1)
    {
        if(s+br[i]<=k){
            s+=br[i];
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;



}

int main()
{
   ll t=1;

   while(t--)
   {
       solve();
   }

}
