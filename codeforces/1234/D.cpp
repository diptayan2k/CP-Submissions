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
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;



ll n;
ll t[26][500001];

void build() {
  f(j,0,25)
  for (ll i = n - 1; i > 0; --i)
    t[j][i] = t[j][i<<1] + t[j][i<<1|1];
}

void modify(ll p, ll c,ll value) {
  p+=n;
  for (t[c][p] = value; p > 1; p >>= 1) t[c][p>>1] = t[c][p] + t[c][p^1];
}

ll query(ll p, ll q) {  // sum on interval [l, r)

  ll s=0;
  f(j,0,25){
  ll res = 0;
  ll l=p;
  ll r=q;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res += t[j][l++];

        if (r&1)
            res += t[j][--r];
    }

  //cout<<res<<" ";
  if(res>0) { /*cout<<(char)(j+'a');*/ s++;
  }
  }

  return s;
}




int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
string s;
cin>>s;
n=s.size();
ll f[26][s.size()];
memset(f,0,sizeof(f));
f(i,0,s.size()-1)
{
    f[s[i]-'a'][i]=1;

}
//f(i,0,25)
//{f(j,0,s.size()-1) cout<<f[i][j]<<" "; cout<<endl;}

f(i,0,25)
f(j,0,n-1)
t[i][j+n]=f[i][j];


build();
/*
cout<<query(0,1,0);
modify(0,0,0);
modify(0,1,1);
cout<<query(0,1,1);*/
/*f(i,0,25)
{
    f(j,0,2*n-1)
    cout<<t[i][j]<<" ";
    cout<<endl;
}*/
ll q;
cin>>q;
while(q--)
{
    ll a,l,r;
    char ch;
    cin>>a;
    if(a==1)
    {
        ll pos;
        cin>>pos>>ch;
        if(ch!=s[pos-1]){
        //cout<<s[pos-1]<<endl;
        modify(pos-1,(ll)(s[pos-1]-'a'),0);
        modify(pos-1,(ll)(ch-'a') ,1);
        s[pos-1]=ch;
        }

    }

    else
    {
        cin>>l>>r;

        cout<<query(l-1,r)<<endl;    }
    /*f(i,0,n)
    {
        f(j,0,25)
        if(t[j][n+i]) cout<<(char)(j+'a');
    }
    cout<<endl;*/



}
}

