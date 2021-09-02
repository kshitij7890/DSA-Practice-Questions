/* Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0 
*/

//Expected Time Complexity: O(N*W)
//Expected Auxiliary Space: O(N*W)

#include<bits/stdc++.h>
using namespace std;


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int dp[n+1][W+1];
   
   for(int i=0;i<=n;i++)
   dp[i][0]=0;
   
   for(int i=0;i<=W;i++)
   dp[0][i]=0;
   
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=W;j++)
       {
           if(wt[i-1]>j)
           {
               dp[i][j]=dp[i-1][j];
           }
           else
           {
               dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
           }
       }
   }
   
   return dp[n][W];
}

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}