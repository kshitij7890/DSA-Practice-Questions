// QUES : Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

// Expected Time Complexity: O(m*n)
// Expected Auxiliary Space: O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {  long long int dp[n+1][m+1];
    
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=1;
        } 
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
        }
    
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(S[j-1]<=i)
                {
                    dp[i][j]+=dp[i-S[j-1]][j];
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}