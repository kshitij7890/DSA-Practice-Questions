/*

Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. 
Now, the task is to find the element which is repeated and number of times it is repeated.
Note: If there's no repeating element, Return {-1,-1}.

Example 1:

Input : N = 5
arr[] = {1,2,3,3,4}
Output: 3 2
Explanation: In the given array, 3 is occuring two times.

Example 2:

Input : N = 5
arr[] = {2,3,4,5,5}
Output: 5 2
Explanation: In the given array, 5 is occuring two times.

Example 3:

Input : N = 3
arr[] = {1,2,3}
Output: -1 -1
Explanation: In the given array, there's norepeating element, and thus the given Output.

Expected Time Complexity: O(logN)
Expected Auxilliary Space: O(1)

*/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findRepeating(int *arr, int n)
{
    pair<int, int> p;
    p.second = n - (arr[n - 1] - arr[0]);

    if (p.second == 1)
        return {-1, -1};

    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int m = (s + e) / 2;

        if (arr[m] >= arr[0] + m) // if a[m] = m + a[0], there is no repeating character in [s..m] // Here arr[m]==arr[0]+m will also work as arr[m] cant be > arr[0]+m
            s = m + 1;
        else // if a[m] < m + a[0], there is a repeating character in [s..m]
            e = m;
    }

    p.first = arr[e];

    return p;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        pair<int, int> ans = findRepeating(arr, n);

        cout << ans.first << " " << ans.second << endl;
    }
}

/*

1) Number of times the element repeats. If the array is sorted and if max-difference of two adjacent elements is 1, then the length of the repeated sequence 
   is n-(arr[n-1]-arr[0])
2) Value of the element : To the value, we do Binary Search.

*/
