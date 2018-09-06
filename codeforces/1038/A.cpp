#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(a,n) for(ll i=a;i<n;i++)
int main()
{ ll n,k,l=0,c=0;
vector <ll> v;
string s;
   cin>>n>>k;
   cin>>s;
   sort(s.begin(),s.end());
   s+="?";
   f(0,n)
   {
      if(s[i]!=s[i+1])
        c++;

      if(c>=k) break;
    }
     //cout<<c<<" ";
    if(k>c) {cout<<0; exit(0);}
    c=0;
    f(0,n)
   {   c++;
      if(s[i]!=s[i+1])
      {
     // cout<<l<<" ";
      v.push_back(c);
      c=0;
      l++;
      }

      if(l>=k) break;
    }
   //cout<<l<<" ";
    //f(0,v.size()) cout<<v[i]<<" ";
    sort(v.begin(),v.end());
    cout<<k*v[0];



    return 0;
}
