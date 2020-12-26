// LCS Variation
// Longest Repeating Subsequence

//QUES : Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character 
//at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

/*
Example:
Input:
2
3
abc
5
axxxy

Output:
0
2
*/

#include<bits/stdc++.h>
using namespace std;

int lrs(int, int, string, string);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s1;
	    cin>>s1;
	    string s2;
	    s2=s1;
	    int res=lrs(n,n,s1,s2);
	    cout<<res<<endl;
	}
	return 0;
}

int lrs(int x, int y, string s1, string s2){
    
    int dp[x+1][y+1];
    
    for (int i = 0; i <= x; i++)  
    {  
        for (int j = 0; j <= y; j++)  
        {  
            
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (s1[i - 1] == s2[j - 1] && i!=j) // (i!=j) has to be checked for lrs
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            
        }  
    } 
    return dp[x][y];
}