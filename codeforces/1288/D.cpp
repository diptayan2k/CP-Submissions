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
ll a[300000][8];
ll n,m;
ll q=-1,r=-1;

bool pod(ll x)
{
    ll msk[1<<m];
    f(i,0,(1<<m)-1) msk[i]=-1;

    f(i,0,n-1)
    {
        ll an=0;
        f(j,0,m-1)
        {
            if(a[i][j]>=x)
            {
                an+=(1<<j);

            }
        }

        msk[an]=i;
       // cout<<an<<" "<<msk[an]<<endl;
    }

    f(i,0,(1<<m)-1)
    {
        f(j,0,(1<<m)-1)
        {
            if(msk[i]!=-1&&msk[j]!=-1&&((i|j)==((1<<m)-1)))
               {
                q=msk[i];
                r=msk[j];
                //cout<<b<<" "<<c
                return true;
               }
        }
    }
    return false;


}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>n>>m;

f(i,0,n-1) f(j,0,m-1) cin>>a[i][j];

//cout<<" "<<q<<" "<<r<<" "<<pod(2);


ll h=(ll)1e9;
ll l=0;
ll mid;
while(h>=l)
{
    mid=(h+l)/2;
    if(pod(mid))
    {
        l=mid+1;
    }
    else{
        h=mid-1;
    }

    //cout<<mid<<endl;
}


cout<<q+1<<" "<<r+1;



}













