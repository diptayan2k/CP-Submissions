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
ll mod=1000000007;



int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n,m,k,l;
cin>>n>>m>>k>>l;

ll dp[n+1][m+1][k+1][l+1];
memset(dp,0,sizeof(dp));
/*
f(i,0,n)
{
   f(j,0,k) dp[i][0][j][0]=1;
}
f(i,0,m)
{
   f(j,0,l) dp[0][i][0][j]=1;
}*/
f(i,0,n)
{
    f(j,0,m)
    {
        f(p,0,k)
        {
            f(q,0,l)
            {
                ll c=0;
                if(i+j==0) c=1;
                else{
                if(i>0&&p>0) c+=dp[i-1][j][p-1][l];
                if(j>0&&q>0) c+=dp[i][j-1][k][q-1];}
               dp[i][j][p][q]=c%100000000;;
               //cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "<<c<<endl;
            }
        }
    }
}
cout<<dp[n][m][k][l];





}
