// Friends Pairing Problem

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countFriendsPairings(int n)
    {
        long long mod = 1e9 + 7;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] % mod) + ((i - 1) * (dp[i - 2] % mod))) % mod;
        }

        return dp[n] % mod;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}