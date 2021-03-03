/*

Given a sorted array arr[] of size N without duplicates, and given a value x. 
Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
Find the index of K(0-based indexing).

Example 1:

Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1"

Example 2:

Input:
N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is2 (i.e K = 2), whose index is 1(0-based indexing)

*/

int findFloor(vector<long long> arr, long long n, long long x)
{
    long long s = 0;
    long long e = n - 1;
    if (arr[0] > x)
        return -1;
    if (arr[n - 1] < x)
        return (n - 1);
    while (s < e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
        {
            e = mid - 1;
        }
        else if (arr[mid] < x)
        {
            s = mid + 1;
        }
    }

    return s;
}

/* 

HINT :
Find the first element in the array which is greater than x.
This can be found using binary search.
The element just before the found element is the floor of x.

*/