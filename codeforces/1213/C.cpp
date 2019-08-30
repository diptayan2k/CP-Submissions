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
ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

bool isSubSequence(string str1, string str2, int m, int n)
{
   int j = 0; // For index of str1 (or subsequence

   // Traverse str2 and str1, and compare current character
   // of str2 with first unmatched char of str1, if matched
   // then move ahead in str1
   for (int i=0; i<n&&j<m; i++)
       if (str1[j] == str2[i])
         j++;

   // If all characters of str1 were found in str2
   return (j==m);
}

int main(){
ll t;
cin>>t;
while(t--){
ll n,m;
cin>>n>>m;
ll p=n/m;
ll c=0;
ll d=p%10;
ll ans=0;
f(i,0,9)
{c+=(m*i)%10;
if(i<=d) ans=c;}

ans+=(p/10)*c;
cout<<ans<<endl;

}
}
