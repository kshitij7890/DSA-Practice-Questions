/*

Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find the number of distinct combinations to reach the given score.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        cout << count(n) << "\n";
    }
    return 0;
}

ll count(ll n)
{

    int dp[n + 1] = {0};
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] += dp[i - 3];

    for (int i = 5; i <= n; i++)
        dp[i] += dp[i - 5];

    for (int i = 10; i <= n; i++)
        dp[i] += dp[i - 10];

    return dp[n];
}