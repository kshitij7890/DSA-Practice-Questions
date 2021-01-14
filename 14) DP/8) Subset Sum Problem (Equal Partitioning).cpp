/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

// Link to its explanation : https://www.geeksforgeeks.org/partition-problem-dp-18/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        if (sum % 2 != 0)
            return false;

        bool dp[n + 1][(sum / 2) + 1];

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int j = 1; j <= sum / 2; j++)
        {
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum / 2; j++)
            {
                if (j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }

        return dp[n][sum / 2];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}