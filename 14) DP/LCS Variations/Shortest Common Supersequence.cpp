// Length of Shortest Common Supersequence
// LCS Variation

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

int lcs(char* X, char* Y, int x, int y){
    
    int dp[x+1][y+1];
    
    for (int i = 0; i <= x; i++)  
    {  
        for (int j = 0; j <= y; j++)  
        {  
            
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            
        }  
    } 
    return dp[x][y];
}

int shortestCommonSupersequence(char* X, char* Y, int m, int n) 
{
    int l = lcs(X, Y, m, n);
    return (m + n - l);
}