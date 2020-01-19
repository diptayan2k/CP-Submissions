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






int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,q;
cin>>n>>q;
map< pair<ll,ll>, ll> m;
//ll count=0;

ll c=0;
while(q--)
{
    ll x,y;
    cin>>x>>y;

    m[{x,y}]++;

    if(x==2){

    if(y>1&&y<n){
        if(m[{1,y}]%2)
        {
            //cout<<m[{x,y}]<<" ";

            if(m[{x,y}]%2==0) { //cout<<" 559 ";
            c--; c=max(c,(ll)0); }
            else c++;

        }

        if((m[{1,y-1}]%2))
        {
            //cout<<m[{x,y}]<<" ";

            if(m[{x,y}]%2==0) { //cout<<" 559 ";
            c--; c=max(c,(ll)0); }
            else c++;

        }
        if(m[{1,y+1}]%2)
        {
            //cout<<m[{x,y}]<<" ";

            if(m[{x,y}]%2==0) { //cout<<" 559 ";
            c--; c=max(c,(ll)0); }
            else c++;

        }
    }

    else if(y==1)
        if(m[{1,2}]%2)
        {
            if(m[{x,y}]%2==0) {c--; c=max(c,(ll)0); }
            else c++;

        }
    }



    else if(x==1){

    if(y>1&&y<n){
        if(m[{2,y}]%2)
        {
            //cout<<m[{x,y}]<<" ";

            if(m[{x,y}]%2==0) { //cout<<" 559 ";
            c--; c=max(c,(ll)0); }
            else c++;

        }

        if((m[{2,y-1}]%2))
        {
            //cout<<m[{x,y}]<<" ";

            if(m[{x,y}]%2==0) { //cout<<" 559 ";
            c--; c=max(c,(ll)0); }
            else c++;

        }
        if(m[{2,y+1}]%2)
        {
            //cout<<m[{x,y}]<<" ";

            if(m[{x,y}]%2==0) { //cout<<" 559 ";
            c--; c=max(c,(ll)0); }
            else c++;

        }
    }


    else if(y==n)
    if(m[{2,n-1}]%2)
        {
            if(m[{x,y}]%2==0) {c--; c=max(c,(ll)0); }
            else c++;
        }

    }
     //cout<<c<<" ";

    if(c==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


}

}
