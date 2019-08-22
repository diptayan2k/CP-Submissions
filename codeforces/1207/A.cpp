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
    ll t;
    cin>>t;
    while(t--)
    {
        ll b,p,f;
        cin>>b>>p>>f;
        ll h,c;
        b/=2;
        cin>>h>>c;
        ll ans=0;
        if(b>p+f)
        {
            ans=p*h+f*c;
        }
        else if(h>c)
        {
            ans=min(b,p)*h+max((b-p),(ll)0)*c;
        }

        else
        {
            ans=min(b,f)*c+max((b-f),(ll)0)*h;
        }
        //ans=min(b,p)*c+max((b-p),(ll)0)*h;
        cout<<ans<<endl;
    }
}
