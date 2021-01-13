/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. 
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 2, K = 10
Output: 4
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 2:

Input:
N = 3, K = 5
Output: 3
------------------------------------------------------------------------------------------------------------------------------------------------------------------
k ==> Number of floors
n ==> Number of Eggs
eggDrop(n, k) ==> Minimum number of trials needed to find the critical
floor in worst case.

eggDrop(n, k) = 1 + min{max(eggDrop(n – 1, x – 1), eggDrop(n, k – x)), where x is in {1, 2, …, k}}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)
------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Function to get minimum number of trials needed in worst case with n eggs and k floors
int eggDrop(int n, int f)
{

    int dp[n + 1][f + 1];
    int res;

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int j = 1; j <= f; j++)
        dp[1][j] = j;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                dp[i][j] = min(
                    dp[i][j],
                    1 + max(
                            dp[i - 1][x - 1],
                            dp[i][j - x]));
            }
        }
    }

    return dp[n][f];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;

        //calling function eggDrop()
        cout << eggDrop(n, k) << endl;
    }
    return 0;
}