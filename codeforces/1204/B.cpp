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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
ll m=1000000007;



void dfs(vv<ll> v[],bool vis[],ll i,ll a[],ll k)
{
      vis[i]=true;
    //cout<<i<<" ";
    a[k++]=i;

    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs(v,vis,v[i][j],a,k);

    }



}


void build_tree( vector<ll>tree[], ll cur , ll l , ll r,ll a[] )
{
     if( l==r )
     {
            tree[cur].push_back( a[ l ] );
            return ;
     }
     ll mid = l+(r-l)/2;
     build_tree(tree,2*cur+1 , l , mid ,a); // Build left tree
     build_tree(tree,2*cur+2 , mid+1 , r ,a ); // Build right tree
     merge(tree[2*cur+1].begin(),tree[2*cur+1].end() , tree[2*cur+2].begin(),tree[2*cur+2].end(),back_inserter(tree[cur]) );
}


ll query( vector<ll>tree[],ll cur, ll l, ll r, ll x, ll y, ll k)
{

      if( x<=l && r<=y )
      {
       return upper_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
      }
      int mid=l+(r-l)/2;
     return query(tree,2*cur+1,l,mid,x,y,k)+query(tree,2*cur+2,mid+1,r,x,y,k);
}







int main(){
ll n,l,r,p;
cin>>n>>l>>r;
ll a[n];
p=1;
f(i,0,l-1) {a[i]=p; p*=2;}
f(i,l,n-1) a[i]=1;
sort(a,a+n);
ll b[n];
p=1;
f(i,0,r-1) {b[i]=p; p*=2; }
p/=2;
f(i,r,n-1) b[i]=p;
ll sum1=0, sum2=0;

f(i,0,n-1) sum1+=a[i];
f(i,0,n-1) sum2+=b[i];
cout<<sum1<<" "<<sum2;
}

/*
1
6
1 2 3
1 6
6 3
3 2
2 4
4 5
*/
