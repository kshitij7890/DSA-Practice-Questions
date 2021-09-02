//QUES : Given a value V and array coins[] of size M, the task is to make the change for V cents, 
//given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. 
//Find the minimum number of coins to make the change. If not possible to make change then output -1

//Expected Time Complexity: O(V*M)
//Expected Auxiliary Space: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[V+1];
	    dp[0]=0;
	    
	    for (int i = 1; i <= V; i++) 
        dp[i] = INT_MAX;
	    
	    for(int i=1;i<=V;i++)
	    {   for(int j=0;j<M;j++)
	        {
	           if(coins[j]<=i)
	           {
	               int subres=dp[i-coins[j]];
	               if(subres!=INT_MAX)
	               {
	                  dp[i]=min(dp[i],subres+1);
	               }
	           }
	        }
	        
	    }
	    
	    if(dp[V]==INT_MAX) return -1;
	    else
	    return dp[V];
	} 
	  
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}