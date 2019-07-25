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



int main(){
   ll q;
   cin>>q;
   while(q--)
   {
       ll n,k;
       cin>>n>>k;
       string s,s1,s2,s3,sd;
       cin>>s;
       f(i,0,n+1)
       sd+="RGB";
       s1=sd.substr(0,s.length());
       s2=sd.substr(1,s.length());
       s3=sd.substr(2,s.length());
       //cout<<sd<<<<endl<<s1<<endl<<s2<<endl<<s3<<endl;
       ll a[s.length()+1]={0},b[s.length()+1]={0},c[s.length()+1]={0};
       f(i,0,s.length()-1)
       {   if(s[i]!=s1[i]) a[i]=1;
           else a[i]=0;
       }
       f(i,0,s.length()-1)
       {   if(s[i]!=s2[i]) b[i]=1;
           else b[i]=0;
       }
       f(i,0,s.length()-1)
       {   if(s[i]!=s3[i]) c[i]=1;
           else c[i]=0;
       }
       /* f(i,0,s.length()) cout<<a[i]<<" ";
       cout<<endl;
       f(i,0,s.length()) cout<<b[i]<<" ";
       cout<<endl;
       f(i,0,s.length()) cout<<c[i]<<" ";
       cout<<endl;*/
       f(i,1,s.length()-1) a[i]=a[i]+a[i-1];
       f(i,1,s.length()-1) b[i]=b[i]+b[i-1];
       f(i,1,s.length()-1) c[i]=c[i]+c[i-1];
      /* cout<<s<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<endl;
       f(i,0,s.length()) cout<<a[i]<<" ";
       cout<<endl;
       f(i,0,s.length()) cout<<b[i]<<" ";
       cout<<endl;
       f(i,0,s.length()) cout<<c[i]<<" ";
       cout<<endl;*/
       g(i,s.length(),1) a[i]=a[i-1];
       g(i,s.length(),1) b[i]=b[i-1];
       g(i,s.length(),1) c[i]=c[i-1];
       a[0]=0;
       b[0]=0;
       c[0]=0;
      /* cout<<s<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<endl;
       f(i,0,s.length()) cout<<a[i]<<" ";
       cout<<endl;
       f(i,0,s.length()) cout<<b[i]<<" ";
       cout<<endl;
       f(i,0,s.length()) cout<<c[i]<<" ";
       cout<<endl;*/
       
      // cout<<endl;
      ll aa=k,bb=k,cc=k;
      f(i,k,s.length()) aa=min(aa,a[i]-a[i-k]);
      f(i,k,s.length()) bb=min(bb,b[i]-b[i-k]);
      f(i,k,s.length()) cc=min(cc,c[i]-c[i-k]);
     cout<<min(aa,min(bb,cc))<<endl;
   }

}
