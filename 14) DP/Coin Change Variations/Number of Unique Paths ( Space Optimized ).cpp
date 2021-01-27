// Auxilary Space : O(b)

#include<bits/stdc++.h>
using namespace std;

int NumberOfPath( int, int);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout << NumberOfPath(a,b) << endl;
    }
}

int NumberOfPath(int a, int b) 
{
    int dp[b]={1};
    dp[0]=1;
    
    for(int i=0;i<a;i++)
    {
       for(int j=1;j<b;j++)
       {
           dp[j]=dp[j]+dp[j-1];
       }
    }
    return dp[b-1];
}