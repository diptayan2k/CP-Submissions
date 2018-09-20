#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define ss string
#define cc char
#define vv vector
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f1(j,c,d) for(ll j=c;j>=d;j--)
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    { ll a=0,b=0,c=0;
    vv <ll> a1,b1,c1;
        ss s;
        cin>>s;
        for(ll i=0;s[i]!='\0';i++)
            {if(s[i]>='a'&&s[i]<='z'){ a++; a1.push_back(i);}
             if(s[i]>='A'&&s[i]<='Z') {b++; b1.push_back(i);}
            if(s[i]>='0'&&s[i]<='9') {c++; c1.push_back(i);}}
        if(a>0&&b>0&&c>0) {cout<<s<<endl; continue;}


          if(a==0)
           {
               if(b>1) s[b1[0]]='a';
               else if(c>1) s[c1[0]]='a';
           }

          if(b==0)
           {
               if(a>1) s[a1[0]]='A';
               else if(c>1) s[c1[1]]='A';
           }
        if(c==0)
           {
               if(a>1) s[a1[1]]='1';
               else if(b>1) s[b1[1]]='1';
           }
        cout<<s<<endl;




    }

    return 0;
}
