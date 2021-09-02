/*
===============================================================================================================================================================
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
===============================================================================================================================================================
Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing number is 6.
===============================================================================================================================================================
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing number is 2.
===============================================================================================================================================================
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
But array will be disoriented after operations
===============================================================================================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
//=============================================================================================================================================================
//Function that puts all non-positive (0 and negative) numbers on left
//side of arr[] and return count of such numbers.
int segregateArr(int arr[], int n)
{
    int j = 0, i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            //Changing the position of negative numbers and 0
            swap(arr[i], arr[j]);
            //Incrementing count of non-positive integers
            j++;
        }
    }
    return j;
}
//=============================================================================================================================================================
//Finding the smallest positive missing number in an array that contains
//all positive integers.
int findMissingPositive(int arr[], int n)
{

    //Marking arr[i] as visited by making arr[arr[i] - 1] negative.
    //Note that 1 is subtracted because index starts from 0 and
    //positive numbers start from 1.
    for (int i = 0; i < n; i++)
    {

        if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }

    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            //Returning the first index where value is positive.
            // 1 is added because index starts from 0.
            return i + 1;

    return n + 1;
}
//=============================================================================================================================================================
//Function to find the smallest positive number missing from the array.
int missingNumber(int arr[], int n)
{
    // First separating positive and negative numbers.
    int shift = segregateArr(arr, n);
    //Shifting the array and calling function to find result in the positive part.
    //returning the result.
    return findMissingPositive(arr + shift, n - shift);
}

int missingNumber(int arr[], int n);
//=============================================================================================================================================================
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
            cin >> arr[i];

        cout << missingNumber(arr, n) << endl;
    }
    return 0;
}