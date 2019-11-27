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


bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
       if(a.first == b.first)
       {
            return (a.second < b.second);
       }

       else
       return (a.first > b.first);
}

int main()
{

ll n;
cin>>n;
ll a[n];

vector< pair<ll,ll> > vvv;
f(i,0,n-1)
{
cin>>a[i];
}

f(i,0,n-1)
vvv.pb({a[i],i});
sort(vvv.begin(),vvv.end(),sortinrev);

ll t;
cin>>t;

vector< pair<pair<ll,ll> , ll > >  q;
ll z=0;
while(t--)
{
    ll k,p;
    cin>>k>>p;
    q.pb({{k,p},z++});
}

sort(q.begin(), q.end());

//f(i,0,q.size()-1) cout<<q[i].F.F<<" "<<q[i].F.S<<" "<<q[i].S<<endl;
pbds ans;
ll disp[z+1];
ll j=0;
f(i,0,q.size()-1)
{
    for( ; j<q[i].F.F; j++)
    {
        //cout<<vvv[j].S<<endl;
        ans.insert(vvv[j].S);
    }
    disp[q[i].S]= *ans.find_by_order(q[i].F.S-1);
   // cout<<q[i].S<<" "<<q[i].F.F<<" "<<disp[q[i].S]<<endl;


}

f(i,0,z-1)
cout<<a[disp[i]]<<endl;

return 0;
}









