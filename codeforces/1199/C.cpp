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
using namespace std;


/*


void dfs(vv<ll> v[],bool vis[],ll i,ll sum[],ll a[], ll c[])
{
      vis[i]=true;
     sum[i]=a[i];
     c[i]=0;

    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs(v,vis,v[i][j],sum,a,c);
    sum[i]+=sum[v[i][j]];
    c[i]++;
    }



}
ll p;
void dfs1(vv<ll> v[],bool vis[],ll i,ll sum[],ll c[], ll a[])
{
      vis[i]=true;


    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs1(v,vis,v[i][j],sum,c,a);
    s=max(s,s-sum[v[i][j]]-m);
    }
    p=p-sum[i]-m;
    s=max(s,p);




}

ll binarySearchCount(ll arr[], ll n, ll key, ll d)
{ ll left =d;
ll     right = n;

    ll mid;
    while (left < right)
    {
        mid = (right + left) >> 1;

        // Check if key is present in array
        if (arr[mid] == key)
        {
            // If duplicates are present it returns
            // the position of last element
            while (mid+1<n && arr[mid+1] == key)
                 mid++;
            break;
        }

        // If key is smaller, ignore right half
        else if (arr[mid] > key)
            right = mid;

        // If key is greater, ignore left half
        else
            left = mid + 1;
    }

    // If key is not found in array then it will be
    // before mid
    while (mid > -1 && arr[mid] > key)
        mid--;

    //Return mid + 1 because of 0-based indexing
    // of array
    return mid-d + 1;
}

*/
bool sortinrev(const pair<ll,ll> &a,
               const pair<ll,ll> &b)
{
       return (a.first > b.first);
}
ll func(string a, string b)
{ string c;
    if(a.length()>b.length())
     { c+=a.substr(0,a.length()-b.length());
    f(i,0,b.length()-1)
    {
      c+=a[a.length()-b.length()+i];
      c+=b[i];
    }}
    if(a.length()==b.length())
     { //c+=a.substr(0,a.length()-b.length());
    f(i,0,b.length()-1)
    {
      c+=a[i];
      c+=b[i];
    }}

    if(a.length()<b.length())
     { c+=b.substr(0,b.length()-a.length());
    f(i,0,a.length()-1)
    {

    c+=a[i];
    c+=b[b.length()-a.length()+i];
    }}
    ll d=0;
    f(i,0,c.length()-1)
    {d=((d*10)%998244353+((ll)c[i]-48)%998244353)%998244353;

    }
    //cout<<c<<endl<<endl;
    return d;
}

ll power(ll x,ll y)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2);
    p = (p * p);

    return (y%2 == 0)? p:(x * p);
}

int main(){
    ll n,d;
    cin>>n>>d;
    ll a[n];
    f(i,0,n-1) cin>>a[i];
    ll s=d*8;
    map <ll,ll> m;
    f(i,0,n-1) m[a[i]]++;
    ll p=m.size();
    sort(a,a+n);
    vector< pair<ll,ll> > v;
    v.pb(mp(a[0],m[a[0]]));
    f(i,1,n-1)
    {
        if(a[i]!=v[v.size()-1].F) v.pb(mp(a[i],m[a[i]]));
    }
    //f(i,0,v.size()-1) cout<<v[i].F<<" "<<v[i].S<<endl;
    ll k=ceil(log(v.size())/log(2));
    //if(log(v.size())%log(2)!=0) k++;
    p=n*k;

    ll b[v.size()-1];
    f(i,0,v.size()-1) b[i]=v[i].S;
    //f(i,0,v.size()-1) cout<<b[i]<<" ";
    ll c[v.size()];

    c[0]=0;
    ll sum=0;
 ll  q=d*8/n;

ll y=1;
 y=power(2,q);
//cout<<m.size()<<" "<<y<<endl;
    if(y>=m.size()||y==0) {cout<<0; exit(0);}
    //cout<<y<<endl;
    f(i,0,v.size()-1)
    {
        sum+=b[i];
        c[i+1]=sum;
    }
      //f(i,0,v.size()) cout<<c[i]<<" ";
    f(i,1,v.size()-y)
    {
        sum=min(sum,c[i-1]+c[v.size()]-c[i+y-1]);
    }
    cout<<sum;

}
