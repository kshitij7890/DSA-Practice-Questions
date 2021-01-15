// O(N^3) Solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string input, int start, int end)
    {

        while (start < end)
        {
            if (input[start] != input[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        int n = str.length();
        int dp[n][n];
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0; i + gap < n; i++)
            {
                int j = i + gap;
                if (isPalindrome(str, i, j) == true)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}