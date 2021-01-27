/*

Find nCr for given n and r.

Example 1
Input: n = 5, r = 2
Output: 10

Expected Time Complexity : O(N*R)
Expected Auxiliary Space: O(R)

In this example :
We take dp array of size r+1

1 0 0 ( dp at initial stage )
  |
1 1 0 ( after 1 iteration )
  |
1 2 1 ( after 2 iterations )
  |
1 3 3 ( after 3 iterations )
  |
1 4 6 ( after 4 iterations )
  |
1 5 10 ( after 5 iterations )

As we can see these are (r+1) elements of each row of pascal triangle

*/

using namespace std;

int nCrModp(int n, int r)
{
    int mod = 1e9 + 7;
    int dp[r + 1] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            dp[j] = ((dp[j] % mod) + (dp[j - 1] % mod)) % mod;
        }
    }

    return dp[r] % mod;
}

int main()
{
    int t, n, r;
    cin >> t;

    while (t--)
    {
        cin >> n >> r;
        cout << nCrModp(n, r) << endl;
    }

    return 0;
}

/*

Explanation: 
1==========>> n = 0, C(0,0) = 1 
1–1========>> n = 1, C(1,0) = 1, C(1,1) = 1 
1–2–1======>> n = 2, C(2,0) = 1, C(2,1) = 2, C(2,2) = 1 
1–3–3–1====>> n = 3, C(3,0) = 1, C(3,1) = 3, C(3,2) = 3, C(3,3)=1 
1–4–6–4–1==>> n = 4, C(4,0) = 1, C(4,1) = 4, C(4,2) = 6, C(4,3)=4, C(4,4)=1 
So here every loop on i, builds i’th row of pascal triangle, using (i-1)th row
At any time, every element of array C will have some value (ZERO or more) and in next iteration, value for those elements comes from previous iteration. 
In statement, 
C[j] = C[j] + C[j-1] 
The right-hand side represents the value coming from the previous iteration (A row of Pascal’s triangle depends on the previous row). 
The left-Hand side represents the value of the current iteration which will be obtained by this statement. 

*/