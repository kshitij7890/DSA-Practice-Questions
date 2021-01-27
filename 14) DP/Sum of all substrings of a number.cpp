/*

Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, print it modulo 10^9+7.

Example 1:

Input:
S = 1234
Output: 1670
Explanation: Sum = 1 + 2 + 3 + 4 + 12 +
23 + 34 + 123 + 234 + 1234 = 1670

*/

#include <bits/stdc++.h>
using namespace std;

long long toDigit(char ch)
{
    return (ch - '0');
}

long long sumSubstrings(string s)
{
    long long mod = 1e9 + 7;
    long long dp[s.length()];
    dp[0] = toDigit(s[0]);
    long long res = dp[0];

    for (int i = 1; i < s.length(); i++)
    {
        dp[i] = (((i + 1) * toDigit(s[i])) + (10 * (dp[i - 1] % mod))) % mod;
        res = (res % mod) + (dp[i] % mod);
    }

    return res % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << sumSubstrings(s) << endl;
    }
    return 0;
}

/*

EXPLANATION :

We can solve this problem by using dynamic programming. We can write a summation of all substrings on basis of the digit at which they are ending in that case, 
Sum of all substrings = sumofdigit[0] + sumofdigit[1] + sumofdigit[2] … + sumofdigit[n-1] where n is length of string.
Where sumofdigit[i] stores the sum of all substring ending at ith index digit, in the above example, 

Example : num = "1234"
sumofdigit[0] = 1 = 1
sumofdigit[1] = 2 + 12  = 14
sumofdigit[2] = 3 + 23  + 123 = 149
sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
Result = 1670
Now we can get the relation between sumofdigit values and can solve the question iteratively. Each sumofdigit can be represented in terms of previous value as shown below, 

For above example,
sumofdigit[3] = 4 + 34 + 234 + 1234
           = 4 + 30 + 4 + 230 + 4 + 1230 + 4
           = 4*4 + 10*(3 + 23 +123)
           = 4*4 + 10*(sumofdigit[2])
In general, 
sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]

*/