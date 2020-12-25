//QUES : Given an array of integers where each element represents the max number of steps that can be made forward from that element.
//Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
//If an element is 0, then cannot move through that element.

/*
Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2
*/

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    int dp[n];
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j + arr[j] >= i)
            {
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[n - 1] == INT_MAX)
        return -1;
    else
        return dp[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}