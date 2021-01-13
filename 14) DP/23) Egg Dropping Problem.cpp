#include <bits/stdc++.h>
using namespace std;

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
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