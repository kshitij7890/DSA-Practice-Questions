/*

Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.

Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.

Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output:
23
Explanation: Sum of the circular 
subarray with maximum sum is 23

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

int max_normal(int arr[], int n)
{
    int currmax = arr[0];
    int res = arr[0];

    for (int i = 1; i < n; i++)
    {
        currmax = max(arr[i], currmax + arr[i]);
        res = max(res, currmax);
    }
    return res;
}

int circularSubarraySum(int arr[], int n)
{
    int res = max_normal(arr, n);
    if (res < 0)
        return res;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        arr[i] = -arr[i];
    }
    int x = max_normal(arr, n);
    x = -x;
    return max(res, sum - x);
}

int main()
{
    int T;

    //testcases
    cin >> T;

    while (T--)
    {
        int num;

        //size of array
        cin >> num;
        int arr[num];

        //inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        //calling function
        cout << circularSubarraySum(arr, num) << endl;
    }

    return 0;
}

/*

There can be two cases for the maximum sum: 
 

Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. 
Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there. 
Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. 
Let us see how. Wrapping of contributing elements implies non-wrapping of non-contributing elements, 
so find out the sum of non-contributing elements and subtract this sum from the total sum. 
To find out the sum of non contributing, invert the sign of each element and then run Kadane’s algorithm. 
Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum 
continuous positive in the inverted arrays. 

Finally, we compare the sum obtained by both cases and return the maximum of the two sums.

*/