/*
PALINDROME PARTIONING O(n^2)

Take example of string "geek" and then solve

P[][] will look like

  0 1 2 3
0|T|F|F|F|
1|X|T|T|F|
2|X|X|T|F|
3|X|X|X|T|

C[] will look like

0|1|1|2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int palindromicPartition(string str)
    {
        int n = str.length();

        /* Create two arrays to build the solution in bottom-up manner 
       C[i] = Minimum number of cuts needed for a palindrome partitioning 
                 of substring str[0..i] 
       P[i][j] = true if substring str[i..j] is palindrome, else false 
       Note that C[i] is 0 if P[0][i] is true */
        int C[n];
        bool P[n][n];

        int i, j, k, L; // different looping variables

        // Every substring of length 1 is a palindrome
        for (i = 0; i < n; i++)
        {
            P[i][i] = true;
        }

        /* L is substring length. Build the solution in bottom up manner by 
       considering all substrings of length starting from 2 to n. */
        for (L = 2; L <= n; L++)
        {
            // For substring of length L, set different possible starting indexes
            for (i = 0; i < n - L + 1; i++)
            {
                j = i + L - 1; // Set ending index

                // If L is 2, then we just need to compare two characters. Else
                // need to check two corner characters and value of P[i+1][j-1]
                if (L == 2)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
            }
        }

        for (i = 0; i < n; i++)
        {
            if (P[0][i] == true)
                C[i] = 0;
            else
            {
                C[i] = INT_MAX;
                for (j = 0; j < i; j++)
                {
                    if (P[j + 1][i] == true && 1 + C[j] < C[i])
                        C[i] = 1 + C[j];
                }
            }
        }

        // Return the min cut value for complete string. i.e., str[0..n-1]
        return C[n - 1];
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