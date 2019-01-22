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


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
string s;
cin>>s;
stack <char> v;
ll c=0;
//v.push(s[0]);
f(i,0,s.length()-1)
{
        if(v.empty())
            v.push(s[i]);

        else if(v.top()==s[i])
        {
            v.pop();
            c++;

        //cout<<c<<endl;
        }
        else v.push(s[i]);


}
if(c%2==0) cout<<"No";
else cout<<"Yes";
	return 0;
}
