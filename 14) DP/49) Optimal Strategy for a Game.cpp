/*
----------------------------------------------------------------------------------------------------------------------------------------------------------------
You are given an array A of size N. The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. 
You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)
------------------------------------------------------------------------------------------------------------------------------------------------------------------
As both the players are equally strong, both will try to reduce the possibility of winning of each other.

F(i, j) represents the maximum value the user
can collect from i'th coin to j'th coin.

F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
              Vj + min(F(i+1, j-1), F(i, j-2) ))
As user wants to maximise the number of coins. 

Base Cases
    F(i, j) = Vi           If j == i
    F(i, j) = max(Vi, Vj)  If j == i + 1
------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

//Expected Time Complexity : O(N*N)
//Expected Auxiliary Space: O(N*N)

#include <bits/stdc++.h>
using namespace std;

long long maximumAmount(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    for (int gap = 3; gap < n; gap += 2)
    {
        for (int i = 0; gap + i < n; i++)
        {
            int j = gap + i;
            dp[i][j] = max(
                arr[i] + min(
                             dp[i + 2][j],
                             dp[i + 1][j - 1]),

                arr[j] + min(
                             dp[i][j - 2],
                             dp[i + 1][j - 1]));
        }
    }
    return dp[0][n - 1];
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {

        int N;
        cin >> N;

        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        cout << maximumAmount(A, N) << endl;
    }
    return 0;
}