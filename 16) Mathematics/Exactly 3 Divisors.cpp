/*

QUES : Given a positive integer value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.

Example 1:
Input:
N = 6
Output: 1
Explanation: The only number with 
3 divisor is 4.
 
Example 2:
Input:
N = 10
Output: 2
Explanation: 4 and 9 have 3 divisors.

*/

#include <bits/stdc++.h>
using namespace std;
/*

Every prime number except 2 and 3 is of the form 6k+1 or 6k-1.
This is because all integers can be expressed as (6k + i) for some integer k and for i = -1, 0, 1, 2, 3, or 4; 
2 divides (6k + 0), (6k + 2), (6k + 4); 
3 divides (6k + 3). 
So a more efficient method is to test if n is divisible by 2 or 3, then to check through all the numbers of form 6k ± 1. 

*/

// Instead of checking till n, we can check till √n because a larger factor of n must be a multiple of smaller factor that has been already checked.
// Therefore Checking for prime function is optimized O(sqrt(n)) instead of O(n).
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) // because i is 6k-1 and i+2 is 6k+1
            return false;

    return true;
}

int exactly3Divisors(int N)
{
    int count = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime(i) == true)
            count++;
    }
    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << exactly3Divisors(N) << endl;
    }
    return 0;
}