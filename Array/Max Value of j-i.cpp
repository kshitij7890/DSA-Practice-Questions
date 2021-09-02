/*

Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Example 1:

Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<=A[1] so (j-i) is 1-0 = 1.

Example 2:

Input:
N = 9
A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array A[1] < A[7]
satisfying the required 
condition(A[i] <= A[j]) thus giving 
the maximum difference of j - i 
which is 6(7-1).

*/

#include <bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n)
{
    int res = -1;
    int lmin[n + 1];
    int rmax[n + 1];
    lmin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lmin[i] = min(arr[i], lmin[i - 1]);
    }
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(arr[i], rmax[i + 1]);
    }

    for (int i = 0, j = 0; i < n, j < n;)
    {
        if (lmin[i] <= rmax[j])
        {
            res = max(res, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return res;
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

        //calling maxIndexDiff() function
        cout << maxIndexDiff(arr, num) << endl;
    }
    return 0;
}

/*

Efficient Logic Used :

To solve this problem, we need to get two optimum indexes of arr[]: left index i and right index j. 
For an element arr[i], we do not need to consider arr[i] for left index if there is an element smaller than arr[i] on left side of arr[i]. 
Similarly, if there is a greater element on right side of arr[j] then we do not need to consider this j for right index. 

So we construct two auxiliary arrays LMin[] and RMax[] such that LMin[i] holds the smallest element on left side of arr[i] including arr[i], 
and RMax[j] holds the greatest element on right side of arr[j] including arr[j]. 

After constructing these two auxiliary arrays, we traverse both of these arrays from left to right. 
While traversing LMin[] and RMa[] if we see that LMin[i] is greater than RMax[j], then we must move ahead in LMin[] (or do i++)
because all elements on left of LMin[i] are greater than or equal to LMin[i]. 
Otherwise we must move ahead in RMax[j] to look for a greater j – i value.

*/