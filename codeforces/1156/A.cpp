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
ll mi;
ll m;

ll s=0;
//vv<ll> m;
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



int main(){
   /*ll t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       sort(s.begin(),s.end());
        string s1;
       f(i,0,s.length()-2)
       {
        f(j,i+1,s.length()-1)
       { if((ll)abs(s[i]-s[j]>=2)||(ll)abs(s[i]-s[j]==0) swap(s[i+1],s[j]);
        }
       }
       ll f=0;
       f(i,0,s.length-2)
       if((ll)abs(s[i]-s[j]==1)) f=1;

       if(f==1) cout<<"No answer"<<endl;
       else cout<<s<<endl;
   }*/
   ll n;
   cin>>n;
   ll a[n];
   f(i,0,n-1) cin>>a[i];
   ll s=0;
   f(i,0,n-2)
   {
       if(a[i]==1&&a[i+1]==2||a[i]==2&&a[i+1]==1) s+=3;
       else if(a[i]==1&&a[i+1]==3||a[i]==3&&a[i+1]==1) s+=4;
       else {s=-1; break;}

   }
   if(s!=-1)
   f(i,0,n-3)
   {
       if(a[i]==3&&a[i+1]==1&&a[i+2]==2) s--;
   }
   if(s==-1) cout<<"Infinite";
   else cout<<"Finite"<<endl<<s;



   return 0;
}

/*
2
3 5
1 -5 -10
1 2
2 3
6 5
1 -2 4 -6 8 10
1 2
1 3
3 4
3 5
3 6
*/
