// LCS Variation
// Minimum number of deletions and insertions to convert string 1 to string 2

// Input: str1 = "heap", str2 = "pea"
// Output: 3

#include <bits/stdc++.h>
using namespace std;

class Solution{
		

	public:
	int lcs(int x, int y, string s1, string s2)
	{
	    int dp[x+1][y+1];
    
        for (int i = 0; i <= x; i++)  
        {  
            for (int j = 0; j <= y; j++)  
            {  
            
               if (i == 0 || j == 0)  
                dp[i][j] = 0;  
      
               else if (s1[i - 1] == s2[j - 1])  
                dp[i][j] = dp[i - 1][j - 1] + 1;  
      
               else
                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        
            }  
        } 
    return dp[x][y];
	}
	
	int minOperations(string s1, string s2) 
	{ 
	    int x=s1.length();
	    int y=s2.length();
	    int common=lcs(x,y,s1,s2);
	    int res=(s1.length()-common)+(s2.length()-common);
	    return res;
	} 
};


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}