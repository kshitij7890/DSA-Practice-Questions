/*

There are N stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
N = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs then 1 stair.
Way 5: Climb 1 stair, then 1 stair and then 2 stairs.
Exam

*/

#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int m)
{
    long long a = 1, b = 1, temp;
    if (m <= 1)
        return 1;
    for (int i = 2; i <= m; i++)
    {
        temp = (a + b) % mod;
        a = b;
        b = temp;
    }

    return temp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //taking stair count
        int m;
        cin >> m;

        cout << countWays(m) << endl;
    }
    return 0;
}