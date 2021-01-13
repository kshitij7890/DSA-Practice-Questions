// QUES : Return the total number of BSTs possible with keys [1....N] inclusive.
/*
Input:
N = 2
Output: 2
Explanation:for N = 2, there are 2 unique
BSTs
     1               2  
      \            /
       2         1

Input:
N = 3
Output: 5
Explanation: for N = 3, there are 5
possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3
*/

// TC : O(N^2)
// AS : O(N)
#include<bits/stdc++.h>
using namespace std;

long long numTrees(long long N) {
    long long dp[N+1];
    int mod = 1000000007;
    dp[0]=1;
    for(long long i=1;i<=N;i++)
    {   dp[i]=0;
        for(long long j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1]; 
            if(dp[i]>=mod) dp[i]%=mod;
        }

    }
    return dp[N];
    
}

#define mod (int)(1e9+7)
int main(){
    
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        cout<<numTrees(n)<<"\n";
    }
}