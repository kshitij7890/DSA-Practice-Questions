/*

A frog jumps either 1, 2, or 3 steps to go to the top. 
In how many ways can it reach the top. 
As the answer will be large find the answer modulo 1000000007.

Example 1:
Input:
N = 1
Output: 1

Example 2:
Input:
N = 4
Output: 7
Explanation : Below are the 7 ways to reach 4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

long long countWays(int n)
{
    long long mod = 1000000007;
    long long a = 1, b = 2, c = 4;
    long long temp;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    for (int i = 4; i <= n; i++)
    {
        temp = (a + b + c) % mod;
        a = b;
        b = c;
        c = temp;
    }

    return temp;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }

    return 0;
}