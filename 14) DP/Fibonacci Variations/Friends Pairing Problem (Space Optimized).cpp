/*

Given N friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. 
Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.

Fibonacci Approach --> O(1) SPACE 

*/

#include <bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n)
{
    int a = 1, b = 2, c = 0;
    if (n <= 2)
    {
        return n;
    }
    for (int i = 3; i <= n; i++)
    {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n = 4;
    cout << countFriendsPairings(n);
    return 0;
}