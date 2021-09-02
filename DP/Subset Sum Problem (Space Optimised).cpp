/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
Subset Sum Problem (Space Complexity Optimized) :
Instead of creating a 2-D array of size (sum/2 + 1)*(n  + 1), we can solve this problem using an array of size (sum/2 + 1 ) only.
part[j] = true if there is a subset with sum equal to j, otherwise false.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(sum * n)
Auxiliary Space: O(sum)

Please note that this solution will not be feasible for arrays with big sum.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0) return false;
        int dp[(sum/2) +1];
        
        for(int i=0;i<=sum/2;i++)
        {
            dp[i]=false;
        }
        
        for(int i=0;i<n;i++)
        {  // the element to be included in the sum cannot be greater than the sum.
            for(int j=sum/2;j>=arr[i];j--)
            {    // check if sum - arr[i] could be formed from a subset using elements before index i
                if(arr[i]==j || dp[j-arr[i]]==1)
                dp[j]=true;
            }
        }
        
        return dp[sum/2];
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
} 