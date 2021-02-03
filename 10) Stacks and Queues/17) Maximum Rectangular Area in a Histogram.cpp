/* 
------------------------------------------------------------------------------------------------------------------------------------------------------
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have the same width and the width is 1 unit.
------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
------------------------------------------------------------------------------------------------------------------------------------------------------
Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)
------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    stack<long long> s;
    long long res = 0, curr, tp;
    for (long long i = 0; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(curr, res);
        }
        s.push(i);
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(curr, res);
    }

    return res;
}

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << getMaxArea(arr, n) << endl;
    }
    return 0;
}