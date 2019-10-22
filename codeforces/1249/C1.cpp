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




int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
//ll pp[11];
//pp[0]=1;
//f(i,1,10) pp[i]=pp[i-1]*3;
cin>>t;
while(t--)
{

ll n;
cin>>n;



int flag=0;
while(flag!=1){
ll a=n;
while(n>0)
{
    if(n%3==2) { break;}
    n/=3;
  if(n==0) flag=1;
}
if(flag==0) n=a+1;
else n=a;
//cout<<n<<endl;
}
cout<<n<<endl;



}


}







