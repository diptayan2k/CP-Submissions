#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,b,a) for(ll i=a;i>=b;i--)
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



int main(){
   ll q;
   cin>>q;
   while(q--)
   {
       ll n,k;
       cin>>n;
       ll x[n],y[n],f1[n],f2[n],f3[n],f4[n];
       f(i,0,n-1)
       cin>>x[i]>>y[i]>>f1[i]>>f2[i]>>f3[i]>>f4[i];
       // xg,xl,yg,yl;
       ll x1=-100000,x2=100000,y1=-100000,y2=100000;
       f(i,0,n-1)
       {
           if(f1[i]==0) x1=max(x1,x[i]);
           if(f2[i]==0) y2=min(y2,y[i]);
           if(f3[i]==0) x2=min(x2,x[i]);
           if(f4[i]==0) y1=max(y1,y[i]);
       }
       
     //cout<<x1<<" "<<x2<<" "<<y1<<" "<<" "<<y2<<endl<<endl;
    
       if(x1>x2||y1>y2) cout<<0<<endl;
       else cout<<1<<" "<<x1<<" "<<y1<<endl;


      // cout<<endl;
   }

}
