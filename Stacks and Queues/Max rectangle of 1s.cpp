/*
------------------------------------------------------------------------------------------------------------------------------------------------------
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.
------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
------------------------------------------------------------------------------------------------------------------------------------------------------
Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)
------------------------------------------------------------------------------------------------------------------------------------------------------
Company Tags
Amazon | Directi | Intuit | MakeMyTrip | Microsoft | Samsung
------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends

int mhist(int arr[], int n)
{

    stack<int> s;

    int tp;
    int res = 0;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {

        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            tp = arr[s.top()];
            s.pop();
            curr = tp * (s.empty() ? i : i - s.top() - 1);
            res = max(curr, res);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        tp = arr[s.top()];
        s.pop();
        curr = tp * (s.empty() ? n : n - s.top() - 1);
        res = max(curr, res);
    }
    return res;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    int res = mhist(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (M[i][j])
                M[i][j] += M[i - 1][j];
        }
        res = max(res, mhist(M[i], m));
    }
    return res;
}