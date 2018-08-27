//By kakarotto_sama, contest: AIM Tech Round 5 (rated, Div. 1 + Div. 2), problem: (A) Find Square, Wrong answer on test 28, #
 #include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long int n,m,end1,start1,end2,start2,i,j;
   string s[1000];
   cin>>n>>m;
   for(i=0;i<n;i++)
    cin>>s[i];
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           if(s[i][j]=='B')
           {
               if(j==0) start1=0;
               else if(s[i][j-1]=='W') start1=j;
           }
           if(s[i][j]=='B')
           {
               if(j==m-1)end1=m-1;
               else if(s[i][j+1]=='W') end1=j;
           }
       }
    }

    for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           if(s[j][i]=='B')
           {
               if(j==0) start2=0;
               else if(s[j-1][i]=='W') start2=j;
           }
           if(s[j][i]=='B')
           {
               if(j==n-1)end2=n-1;
               else if(s[j+1][i]=='W') end2=j;
           }
       }
    }
 // cout<<start1<<" "<<end1<<" "<<start2<<" "<<end2<<" ";
  cout<<start2+(end2-start2)/2+1<<" "<<start1+(end1-start1)/2+1;
    return 0;
}