//QUES : Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that 
//the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers. After performing 
//all the cut operations, your total number of cut segments must be maximum.

//Expected Time Complexity : O(N)
//Expected Auxiliary Space: O(N)

/* Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;

        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    dp[0]=0;
    
    for(int i=1;i<=n;i++)
    {   dp[i]=-1;
        if(i-x>=0) dp[i]=max(dp[i],dp[i-x]);
        if(i-y>=0) dp[i]=max(dp[i],dp[i-y]);
        if(i-z>=0) dp[i]=max(dp[i],dp[i-z]);
        if(dp[i]!=-1)
        dp[i]++;
    }
    if(dp[n]==-1)return 0;
    else
    return dp[n];
}