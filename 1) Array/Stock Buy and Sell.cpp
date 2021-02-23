/*

The cost of stock on each day is given in an array A[] of size N. 
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
(0 3) (4 6)
Explanation:
We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit. Now, we buy stock on day 4 and sell it on day 6.

Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
(3 4)
Explanation:
We can buy stock on day 3,and sell it on 4th day, which will give us maximum profit.


Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Interval
    {
        int buy;
        int sell;
    };
    vector<vector<int>> stockBuySell(vector<int> arr, int n)
    {
        vector<vector<int>> res;
        int count = 0;
        if (n == 1)
            return res;            // Prices must be given for at least two days
        Interval sol[(n / 2) + 1]; // solution vector

        for (int i = 0; i < n;)
        {
            while (arr[i + 1] <= arr[i] && i < n - 1)
                i++; // Find Local Minima

            if (i == n - 1)
                break; // If we reached the end, break

            sol[count].buy = i; // Store the index of minima
            i++;

            while (arr[i] >= arr[i - 1] && i < n)
                i++; // Find Local Maxima

            sol[count].sell = i - 1; // Store the index of maxima

            count++; // Increment count of buy/sell pairs
        }

        if (count == 0)
            return res;
        else
        {
            for (int i = 0; i < count; i++)
            {
                vector<int> temp;
                temp.push_back(sol[i].buy);
                temp.push_back(sol[i].sell);
                res.push_back(temp);
            }
        }

        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.stockBuySell(A, n);
        if (ans.size() == 0)
            cout << "No Profit";
        else
        {
            for (int i = 0; i < ans.size(); ++i)
            {
                cout << "(" << ans[i][0] << " " << ans[i][1] << ") ";
            }
        }
        cout << endl;
    }
    return 0;
}