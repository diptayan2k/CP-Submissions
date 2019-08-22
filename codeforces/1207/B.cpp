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
#include <iostream>

using namespace std;




int main(){
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    ll b[n][m];
    f(i,0,n-1) f(j,0,m-1) {cin>>a[i][j]; b[i][j]=0;}
    ll c=0;
    vv<pair <ll,ll> > v;
    f(i,0,n-2) f(j,0,m-2)
    if((a[i][j]!=b[i][j])||(a[i+1][j]!=b[i+1][j])||(a[i][j+1]!=b[i][j+1])||(a[i+1][j+1]!=b[i+1][j+1]))
    {   if(a[i][j]&a[i+1][j]&a[i][j+1]&a[i+1][j+1]==1){
        c++;
        b[i][j]=1;
        b[i+1][j]=1;
        b[i][j+1]=1;
        b[i+1][j+1]=1;
        v.pb(mp(i+1,j+1));}
    }

    f(i,0,n-1) f(j,0,m-1) if(a[i][j]!=b[i][j]) {cout<<-1; exit(0);}

        cout<<c<<endl;
        if(c>0)
        {
            f(i,0,v.size()-1) cout<<v[i].F<<" "<<v[i].S<<endl;
        }



}
